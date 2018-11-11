#include <iostream>
#include <string>
#include <sstream>
#include "sensor_network.hpp"
#include "array.hpp"
#include "sensor.hpp"
#include "dato.hpp"
#include "node.hpp"
#include "segmentTree.hpp"

using namespace std;

sensorNetwork::sensorNetwork()
{
  quantity = 0;
}

sensorNetwork::sensorNetwork(array <sensor> d,int n)
{
  network = d;
  quantity = n;
}

sensorNetwork::sensorNetwork(int n)
{
  array <sensor> aux(n);
  network = aux;
  quantity = n;
}

sensorNetwork::sensorNetwork(const sensorNetwork &d)
{
  network = d.network;
  quantity = d.quantity;
}

sensorNetwork::~sensorNetwork()
{
  //Destructor
}

int sensorNetwork::get_quantity() const
{
  return quantity;
}

sensor sensorNetwork::get_sensor(const int n) const
{
  return network[n];
}

ostream & operator<<(ostream &os,const sensorNetwork & s)
{
  for(int i = 0;i < s.quantity;i++)
  {
    os << s.network[i];
    os << '\n';
  }
  return os;
}

status_t sensorNetwork::process_input_file(istream &iss)
{
  //Esta funcion carga los datos de un archivo a la red de
  //sensores
  //variables auxiliares
  array <string> auxSensorsParse;
  string s;
  string sd;
  //Leo la primera linea, y me fijo cuantos sensores tengo
  //Guardo los nombres


  getline(iss,s,'\n');

  if(s.empty())
    return ERROR_EMPTY_FILE;

  size_t posr = s.find('\r');
  if(posr != string::npos)      //Con esto se soluciona lo del '\r'
    s.erase(posr);

  stringstream str(s); //transformo la linea en un strigstream
  while(getline(str,s,',')){ //ahora la parseo por comas
    auxSensorsParse.push_back(s); //voy guardando los nombres en un array de strings
  }
  int sensor_quant = auxSensorsParse.get_size();

  //Red de sensores auxiliar;
  sensorNetwork pr(sensor_quant); //se crea una red con la cantidad de sensores

  for(int i = 0;i<sensor_quant;i++){
		pr.network[i].set_name(auxSensorsParse[i]); //se guardan los nombres en la red

  }

    double d;
    int aux = 0;
    //Ahora se parsean los valores
    while(getline(iss,s,'\n') && (!iss.eof()))
    {
      if(s == "\r")
        continue;
      stringstream str_is(s);
      while(getline(str_is,s,',') && (aux != sensor_quant)){
        stringstream auxs(s);
        if(auxs >> d)      //Aca me fjo si el valor es distinto de null
        {
          dato measure(d);
          pr.network[aux].push_back_data(measure);
        }else{
          dato measure(0,false);
          pr.network[aux].push_back_data(measure);
    	  }
    	aux++;
    }

    if(aux < sensor_quant){ //Con esto se cargan las mediciones falntantes con datos inválidos
      for(int i = aux;i<sensor_quant;i++){
        dato measure(0,false);
        pr.network[i].push_back_data(measure);
      }
    }

    aux = 0;
  }

  network = pr.network;
  quantity = pr.quantity;
  return OK;
}

int sensorNetwork::get_sensor_data_size(int i) const
{
  return (network[i].get_data()).get_size();
}

void sensorNetwork::process_query(istream &iss, ostream &oss)
{
  //Aca se van procesando las consultas, a medidad que van llegando
  //se procesa y se imprime, luego se pasa a otra consulta

  string s;
  string name;
  string limits;

  int init=0, end=0, unused=0,j=0;
  double min=0, max=0, mean=0;

  while(getline(iss,s,'\n') && (!iss.eof()))
  {
    if(s == "\r")
      continue;
    stringstream str_is(s);
    getline(str_is,name,',');
    getline(str_is,limits,',');
    stringstream str(limits);
    getline(str_is,limits,',');
    stringstream str1(limits);

    if(!(str >> init) || !(str1 >> end) || (end <= init) || (end < 0) || (init<0))
    {
      oss<<BAD_QUERY_MSG<<endl;
    }
    else
    {
      end = end - 1; //end-1 para que el intervalo que evalue sea abierto
      for(j = 0;(j < quantity) && name.compare(network[j].get_name());j++); //Esto me devuelve en j el numero del sensor
                                                                            //Correspondiente
      if(j != quantity) //Si j es distinto a la cantidad, entonces, el sensor de consulta está en la red.
      {
        if(get_sensor_data_size(j)-1 < init)
          oss << NO_DATA_MSG << endl;
        else{
          if(network[j].query(init, end, min, max, mean, unused)) //Si esta funcion devuleve falso es porque no hay data
            oss<<mean<<DELIM<<min<<DELIM<<max<<DELIM<<end+1-init-unused<<endl;
          else
            oss << NO_DATA_MSG << endl;
        }
      }

      else if(j == quantity && (!name.compare(""))) //Si j es cantidad y el nombre del sensor es vacío, entonces calculo el
      {                                             //promedio de todos los sensores

        if((this -> get_sensor_data_size(0))-1 < init)  //Me fijo si el primer sensor guradado en la red supera el rango
        {                                               //y asumo q los otros tambien lo superan.
          oss << NO_DATA_MSG << endl;
        }
        else
        {
          sensor mega = this->merge_beta(init,end);
          if(mega.query(init, end, min, max, mean, unused))
            oss<<mean<<DELIM<<min<<DELIM<<max<<DELIM<<end+1-init-unused<<endl;
          else
            oss << NO_DATA_MSG << endl;
        }
      }
      else{
        oss<<UNKNOWN_ID_MSG<<endl;
      }
    }
  }

}

dato  sensorNetwork::get_sensor_network_mean_instant(int in)
//Esto hay que cambiarlo para que no tenga en cuenta los datos invalidos
{
//Esta funcion devuelve el promedio de algun instante "in"
//de los sensores cargados en la red
//Si hay un valor inválido no se tendrá en cuenta para el promedio

    double aux = 0;
    int auxQuant = quantity;
    double validation;
    
    for(int i = 0;i<quantity;i++){
      if(!(network[i].get_data_value(in,validation))) //Si el valor es inválido, entonces, no lo tengo
      {                                                                 //en cuenta para el promedio
        validation = 0;
        auxQuant = auxQuant-1;
      }

      aux += validation;
    }
    if(auxQuant ==0){
      dato mean(0, false);
      return mean;
    }
    else{
      dato mean(aux/auxQuant, true);
      return mean;
    }
}

sensor sensorNetwork::merge_beta(int init, int &end){
//Esta funcion devuelve un sensor con los promedios de cada
//Instante de todos los sensores cargados en la red

  array <dato> aux; //Array auxiliar

  if((this -> get_sensor_data_size(0))-1 < end) //Si la cota superior es mayor a la cantidad de detos
    end = (this -> get_sensor_data_size(0))-1;  //Ahora la cota superior es la cantidad de daatos

  for(int i = 0;i<=end;i++){ //Guarda en un sensor auxiliar los promedios de los instantes 0 a end
    aux.push_back(this->get_sensor_network_mean_instant(i));
  }

  sensor auxSensor("",aux); //Crea un sensor auxiliar

  return auxSensor;
}

void sensorNetwork::buildSegmentTrees(){
  for(int i = 0; i<quantity;i++){
    network[i].loadTree();
  }
}


void sensorNetwork::process_query_tree(istream &iss, ostream &oss)
{
  //Aca se van procesando las consultas, a medidad que van llegando
  //se procesa y se imprime, luego se pasa a otra consulta

  string s;
  string name;
  string limits;

  int init=0, end=0, j=0;

  while(getline(iss,s,'\n') && (!iss.eof()))
  {
    if(s == "\r")
      continue;
    stringstream str_is(s);
    getline(str_is,name,',');
    getline(str_is,limits,',');
    stringstream str(limits);
    getline(str_is,limits,',');
    stringstream str1(limits);

    if(!(str >> init) || !(str1 >> end) || (end <= init) || (end < 0) || (init<0))
    {
      oss<<BAD_QUERY_MSG<<endl;
    }
    else
    {
      //end = end - 1; //end-1 para que el intervalo que evalue sea abierto
      for(j = 0;(j < quantity) && name.compare(network[j].get_name());j++); //Esto me devuelve en j el numero del sensor
                                                                            //Correspondiente
      if(j != quantity) //Si j es distinto a la cantidad, entonces, el sensor de consulta está en la red.
      {
        if(get_sensor_data_size(j)-1 < init)
          oss << NO_DATA_MSG << endl;
        else{
          int length = sizeRound(get_sensor_data_size(j));
          if(end>length){
            end  = length;
          }
          node aux_node = network[j].queryTree(0, 1, length, init+1, end);
          if((aux_node.isNodeUseful()) == false)
            oss << NO_DATA_MSG << endl;
          else
            cout << aux_node;
        }
      }
      else if(j == quantity && (!name.compare("")))
      {
        if((this -> get_sensor_data_size(0))-1 < init)  //Me fijo si el primer sensor guradado en la red supera el rango
        {                                               //y asumo q los otros tambien lo superan.
          oss << NO_DATA_MSG << endl;
        }
        else
        {
          int lengthMega = this->get_sensor_data_size(0);
          sensor mega = this->merge_beta(0,lengthMega);
          mega.loadTree();
          int length = sizeRound(lengthMega);
          if(end>length){
            end  = length;
          }
          node aux_node1 = mega.queryTree(0, 1, length, init+1, end);
          if((aux_node1.isNodeUseful()) == false)
            oss << NO_DATA_MSG << endl;
          else
            cout << aux_node1;
        }

      }
      else{
        oss<<UNKNOWN_ID_MSG<<endl;
      }
    }
  }

}

int sensorNetwork::sizeRound(int lengthData){
  int f = 2;
  int i=1;
  while(i < lengthData){ //calculo la potencia de dos correspondiente
    i = i*f;
  }
  //el segment tree sera de largo 2*i-1, por lo tanto:
  //i = 2*i -1;
  return i;
}
