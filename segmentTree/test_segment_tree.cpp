#include <iostream>
#include "dato.hpp"
#include "node.hpp"
#include "array.hpp"
#include "segmentTree.hpp"


using namespace std;

//********************************************SEGMENT_TREE_PRUEBAS************************************//
//Pruebas automatizadas para la clase segment tree
//****************************************************************************************************//

int main (void)
{
  char c;
  int i;
  double f = 15;
  segmentTree tree;

  while(cin >> c)
  {
    switch (c)
    {
      case 'L':
      {
        cout << "Cargar arbol ";
        cout << endl;
        array <dato> arr;
        for(int j = 0; j < f; j++){
          arr.push_back(j+1);
        }
        cout << "Vector Cargado: " << endl;
        cout << arr;
        cout << endl;
        segmentTree aux(arr,f);
        tree = aux;
      }
      break;

      case 'N':
      {
        cout << "Imprimir Nodo: ";
        if(cin >> i){
          node aux4 = tree.getNode(i);
          cout << aux4;
        }
      }
      break;

      case 'P':
      {
        cout << "Imprimir arbol: ";
        array <node> aux;
        for(int i = 0;i < (2*16 - 1);i++)
          aux.push_back(tree.getNode(i));

        cout << aux;
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
