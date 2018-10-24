#include <iostream>
#include "array.hpp"
#include "sensor.hpp"
#include "dato.hpp"
#include "node.hpp"
#include "segmentTree.hpp"

using namespace std;

void display_attribute(node );
void print_tree_max(segmentTree test);

//*************************TEST_NODE_SEGMENTTREE***************************************//
//En este archivo se realiza el testeo tanto de la clase nodo como el de SegmentTree.
//En principio se realizan las pruebas por separado, luego se inculirá un menú para
//poder elegir el testeo se re requiera.
//************************************************************************************+//

int main(void)
{

//***********************************TESTE_CLASE_NODO+++++++*****************************//
/*
  cout << "Se crea un nodo con el contructor por defecto" << endl;
  node test_node;
  display_attribute(test_node);

  cout << "Testeo del constructor con dos double" << endl;
  node test_node1(1,2);
  display_attribute(test_node1);

  cout << "Constructor apartir de un dato" << endl;
  dato uno(1,true);
  node test_node2(uno);
  display_attribute(test_node2);
*/

//***********************************TESTE_CLASE_SEGMENT_TREE*****************************//
  array <dato> v;

  int n = 6;
  for(double i = 0;i < n;i++)
    v.push_back(i);

  cout << v << endl;
  segmentTree test(v,n);

  int m = test.treeSize(n);
  for(int i = 0;i <(2*m)-1;i++)
    display_attribute(test.getNode(i));

  return 0;
}


void display_attribute(node test_node)
{
  double max = test_node.getMax();
  double min = test_node.getMin();
  double adds = test_node.getAddsUp();
  double quant = test_node.getQuantity();

  cout << "Se muestran por pantalla los atributos" << endl;
  cout << "El mínimo es: " << min << "\t";
  cout << "El máximo es: " << max << endl;
  cout << "AddsUp: " << adds << endl;
  cout << "La cantidad: " << quant << endl;
}
