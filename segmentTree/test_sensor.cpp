#include <iostream>
#include "dato.hpp"
#include "node.hpp"
#include "array.hpp"
#include "segmentTree.hpp"
#include "sensor.hpp"

using namespace std;

//********************************************CLASE_SENSOR_RPUEBAS************************************//
//Pruebas automatizadas para la clase Sensor
//****************************************************************************************************//

int main (void)
{

  char c;
  sensor s;
  node aux_node;
  array <node> aux;
  segmentTree aux_tree;

  while(cin >> c)
  {
    switch (c)
    {
      case 'L':
      {
        cout << "Cargar sensor";
        cout << endl;
        array <dato> aux;
        for(int i = 0;i<4;i++)
          aux.push_back(i+100);

        cout << "Vector de carga:";
        cout << endl;
        cout << aux;
        cout << endl;

        sensor aux_s("Prueba",aux);
        s = aux_s;

      }
      break;

      case 'G':
      {
        cout << "Obtener Arbol: ";
        cout << endl;
        aux_tree = s.get_tree();

        for(int i = 0;i < (2*4 - 1);i++)
          aux.push_back(aux_tree.getNode(i));

        cout << aux;
        cout << endl;
      }
      break;

      case 'Q':
      {
        cout << "Query";
        cout << endl;
        int init,end;
        if(cin >> init && cin >> end){
          aux_node = s.queryTree(0,1,4,init+1,end);
        }
        cout << "Consulta: ";
        cout << aux_node;
        cout << endl;
      }
      break;

      case 'T':
      {
        cout << "Crear Arbol";
        cout << endl;
        s.loadTree();
      }
      break;

      case 'P':
      {
        cout << "Imprmir sensor: ";
        cout << endl;
        cout << s;
        cout << endl;
      }
      break;

      default:
        cout << "error: unknown command (";
        cout << c;
        cout << ")";
        cout << endl;
        break;

    }
  }

  return 0;
}
