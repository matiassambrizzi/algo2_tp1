#include <iostream>
#include "array.hpp"
#include "sensor.hpp"
#include "node.hpp"
#include "dato.hpp"
#include "segmentTree.hpp"


segmentTree::segmentTree(){

}

//********************************Constructor************************************//
//Este contructor recibe un array de datos y la cantidad
//Si la cantidad no es multiplo de 2^n se agregaran datos
//inválidos para poder generar un arbol binario completo
segmentTree::segmentTree(array <dato> arr, double quant)
{

	int q = treeSize(quant);
	array <dato> aux1(q);

	for(int i = 0;i < quant;i++){
		aux1[i] = arr[i];
	}

	array <node> aux(2*q - 1);
	tree = aux;

	buildSegmentTree(aux1,0,0,q-1);
}
//*******************************************************************************//

//********************************DESTRUCTOR************************************//
segmentTree::~segmentTree()
{

}
//**************************************************++++++++++++++++++++++++++++//

//************************************Tamaño_del_arbol*****************************************//
//Esta funcion devuelve el tamaño del arbol
int segmentTree::treeSize(int lengthData){
	int f = 2;
	int i=1;
	while(i < lengthData){ //calculo la potencia de dos correspondiente
		i = i*f;
	}
	//el segment tree sera de largo 2*i-1, por lo tanto:
	//i = 2*i -1;
	return i;
}
//*********************************************************************************************//

//************************************Get_Node*****************************************//
node segmentTree::getNode(int n)
{
	return tree[n];
}
//*************************************************************************************//


//************************************ARMAR_ARBOL*****************************************//
//La funcion tiene como parámetros un array, un index que se corresponde con el nodo al que
//pertenece el dato y el inicio y fin del array que se esta evaluando
void segmentTree::buildSegmentTree(array <dato> d,double index,double init,double final)
{
	//********CASO_BASE*****************//
	if(init == final)
	{
		node aux1(d[init]);
		tree[index] = aux1;           //Aca hay que identificar que este nodo es una hoja
		return;
	}
	//********FIN_CASO_BASE*************//

	int mid = (init + final)/2; 			//Se calcula el medio para dividir el array
	double leftIndex = 2*index + 1;			//Indices de los hijos izquierdo y derecho
	double rightIndex = 2*index + 2;

	//Luego se realizan las llamadas recursivas
	buildSegmentTree(d,leftIndex,init,mid);
	buildSegmentTree(d,rightIndex,mid+1,final);

	//Por último se tendrá que implementar una función para fusionar dos nodos
	node aux(tree[leftIndex],tree[rightIndex]);
	tree[index] = aux;
}
//****************************************************************************************//

node & segmentTree::operator[](int pos){
	return tree[pos];
}


//*********************************DESACTUALIZADO****************************************//
/*
void segmentTree::buildSegmentTree(array <dato> d){
	initializeSegmentTree(d, lengthTree);


	if(end  ==  init +1){

	}
	for(int i = init;i<end ;i = i+2 ){
		//la posicion inicial en la que se va a guardar seria (init-1)/2
		if(data[i].dato_available() == true && data[i+1].dato_available() == true){
			if(data[i].get_dato()<data[i].get_dato()){
				//aca habria que guardar en el node el minimo, maximo, suma y cantidad segun corresponda
			}
			else{
				//idem anterior
			}
		}
		else if(data[i].dato_available() == true && data[i+1].dato_available() == false){
			//habria que guardar en el node como que maximo y minimo son el i
		}
		else if(data[i].dato_available() == false && data[i+1].dato_available() == true){
			//habria que guardar en el node como que maximo y minimo son el i+1
		}
	}
}

void segmentTree::initializeSegmentTree(const array <dato> d, int lengthTree){
	int start = (lengthTree+1)/2-1;
	for(int i = start; i < lengthTree; i++){
		tree[start] = d[start];
	}
}

segmentTree::segmentTree(const array <dato> d){

	int lengthTree = this->treeSize(d.get_size());

	array <node> tree(lengthTree);

	int start = (lengthTree+1)/2-1;

	//Aca me parece que tiene q ser menor o igual a lengthTree
	for(int i = start; i < lengthTree; i++){
		tree[start] = d[start];
	}

	unsigned int end = start;
	unsigned int j = (end-1)/2;

	while(j!=0){
		if(j == end){
			end =  (end-1)/2;
			j = (end-1)/2;
		}
		else{
			node a(tree[2*j+1],tree[2*j+2]);
			tree[j] = a;
			j++;
		}
	}
	node a(tree[2*j+1],tree[2*j+2]); //agrego el caso en el que j == 0
	tree[j] = a;

}

*/
