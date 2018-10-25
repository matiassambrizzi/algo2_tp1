#include <iostream>
#include "dato.hpp"
#include "node.hpp"
#include "array.hpp"

using namespace std;

//*************************TEST_NODE***************************************************//
//En este archivo se realiza el testeo de la clase nodo
//*************************************************************************************//

int main(void)
{
  char c;
  double i;
  node test;
  node empty;
  node aux;

  while(cin >> c)
  {
    switch (c)
    {
      case 'Y':
      //SetMin
        if(cin >> i)
        {
          cout << "min: ";
          cout << i;
          cout << endl;
          test.setMin(i);
        }
        break;

      case 'X':
      //SetMax
      if(cin >> i)
      {
        cout << "max: ";
        cout << i;
        cout << endl;
        test.setMax(i);
      }
      break;

      case 'D':
      {
         cout << "Nodo conteniendo un dato:";
         cout << endl;
         dato d(1,true);
         cout << "Dato: ";
         cout << endl;
         cout << d.get_dato();
         cout << "; Existe: ";
         cout << d.dato_available();
         cout << endl;
         node aux5(d);
         cout << "Max: ";
         cout << aux5.getMax();
         cout << " Min:";
         cout << aux5.getMin();
         cout << endl;
      }
      break;

      case 'M':
      {
        node aux2(1,5);
        node aux3(30,40);
        cout << "Merge: ";
        cout << endl;
        cout << "(Max,Min)";
        cout << endl;
        cout << "Node1: (";
        cout << aux2.getMax();
        cout << ',';
        cout << aux2.getMin();
        cout << ')';
        cout << endl;
        cout << "Node2: (";
        cout << aux3.getMax();
        cout << ',';
        cout << aux3.getMin();
        cout << ')';
        cout << endl;
        node aux4(aux2,aux3);
        cout << "MergeNode: (";
        cout << aux4.getMax();
        cout << ',';
        cout << aux4.getMin();
        cout << ')';
        cout << endl;

      }
      break;
      case 'E':
      //vaciar; fijar max y min 0
        cout << "Vacío";
        cout << endl;
        test = empty;
        aux = empty;
        break;

      case 'P':
        cout << "Mínimo: ";
        cout << test.getMin();
        cout << endl;
        cout << "Maximo: ";
        cout << test.getMax();
        cout << endl;
        break;

      case 'R':
        return 0;
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
