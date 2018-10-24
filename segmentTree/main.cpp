#include <iostream>
#include "array.hpp"
#include "node.hpp"
#include "sensor.hpp"
#include "segmentTree.hpp"
#include "dato.hpp"

using namespace std;

void display_attribute(node );

//*************************TEST_NODE_SEGMENTTREE***************************************//
//En este archivo se realiza el testeo tanto de la clase nodo como el de SegmentTree.
//En principio se realizan las pruebas por separado, luego se inculirá un menú para
//poder elegir el testeo se re requiera.
//************************************************************************************+//
int main(void)
{

  //****Testeo del contructor por defecto****//
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

  array <double> v;
  for(double i=0;i<8;i++)
    v.push_back(i);

  cout << v << endl;
  segmentTree test(v,8);

  for(int i = 0;i < (2*8) - 1;i++)
    display_attribute(test.getNode(i));

  return 0;
}


void display_attribute(node test_node)
{
  double min = test_node.getMax();
  double max = test_node.getMin();
  double adds = test_node.getAddsUp();
  double quant = test_node.getQuantity();

  cout << "Se muestran por pantalla los atributos" << endl;
  cout << "El mínimo es: " << min << endl;
  cout << "El máximo es: " << max << endl;
  cout << "AddsUp: " << adds << endl;
  cout << "La cantidad: " << quant << endl;
}
