#ifdef SENSOR__HPP

#include <iostream>
#include "array.hpp"
#include "dato.hpp"
#include "sensor.hpp"
#include "segmentTree.hpp"

using namespace std;


sensor::sensor()
{
  //array <double> aux;

  //data = aux;
  //name = "";
}

sensor::sensor(string n, array<dato> d)
{
    data = d;
    name = n;
}

sensor::sensor(const sensor &d)
{
  data = d.data;
  name = d.name;
}


sensor::~sensor()
{

}

string sensor::get_name() const
{
  return name;
}

array <dato> sensor::get_data() const
{
  return data;
}

void sensor::set_name(string n)
{
  name = n;
}

void sensor::set_data(array <dato> d)
{
  data = d;
}

void sensor::print(ostream &os)
{
  data.print(os,data.get_size());
  os<<name<<endl;
}

ostream& operator<<(ostream &os,const sensor &s)
{
  os << s.name;
  os << '\n';
  os << s.data;
  return os;
}

void sensor::push_back_data(const dato a)
{
  data.push_back(a);
}

bool sensor::query(int pos1, int &pos2, double &min, double &max, double &mean, int &unused){
  //Aca se calculan tanto el maximo, el minimo como el promedio.
	int i=0;
  unused = 0;

  while(data[pos1+unused].dato_available() == false){
    if((pos1+unused) == (pos2))
      return false;
    unused++;
  }

  min = data[pos1+unused].get_dato(); //corrijo al primer valor segun cuantos no existian
	max = min;
	mean = 0;

  if(((data.get_size())-1) < pos2)
    pos2 = data.get_size() -1;

	for(i = pos1; i<=pos2; i++){
    if(data[i].dato_available() == false){
      unused++;
    }
    else{
  		if(data[i]<min){
  			min = data[i].get_dato();
  		}
  		else if(data[i]>max){
  			max = data[i].get_dato();
  		}
  		mean += data[i].get_dato();
    }
	}

  mean = mean/(pos2 - pos1 - unused + 1);
  return true;
}

bool sensor::get_data_value(int pos,double &val){
    if(data[pos].dato_available()){
      val = data[pos].get_dato();
      return true;
    }
    else{
      return false;
    }
}

void sensor::buildSegmentTree(){
  segmentTree auxTree(this->data);
  tree = auxTree;
}


#endif
