#include <iostream>
#include "array.hpp"
#include "sensor.hpp"
#include "dato.hpp"
#include "node.hpp"
#include "segmentTree.hpp"

using namespace std;

//*************************TEST_NODE_SEGMENTTREE***************************************//
//En este archivo se realiza el testeo tanto de la clase nodo como el de SegmentTree.
//En principio se realizan las pruebas por separado, luego se inculirá un menú para
//poder elegir el testeo se re requiera.
//************************************************************************************+//
int main(void)
{

  cout << "Se crea un nodo con el contructor por defecto" << endl;
  node test_node;

  double min = test_node.getMax();
  double max = test_node.getMin();
  double adds = test_node.getAddsUp();
  double quant = test_node.getQuantity();

  cout << "Se muestran por pantalla los atributos" << endl;
  cout << "El mínimo es: " << min << endl;
  cout << "El máximo es: " << max << endl;
  cout << "AddsUp: " << adds << endl;
  cout << "La cantidad: " << quant << endl;





  return 0;
}
