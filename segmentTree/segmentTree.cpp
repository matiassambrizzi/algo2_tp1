#include <iostream>
#include "array.hpp"
#include "sensor.hpp"
#include "node.hpp"
#include "dato.hpp"
#include "segmentTree.hpp"


segmentTree::segmentTree(){

}

segmentTree::segmentTree(array <double> arr, double quant)
{
	//Falta poner que si el largo no es 2^n agregue datos no existentes
	array <node> aux(2*quant - 1);
	tree = aux;

	buildSegmentTree(arr,0,0,quant-1);
}

node segmentTree::getNode(int n)
{
	return tree[n];
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

segmentTree::~segmentTree(){
}

int segmentTree::treeSize(int lengthData){
	int i = 2;
	while(i < lengthData){ //calculo la potencia de dos correspondiente
		i = i*i;
	}
	//el segment tree sera de largo 2*i-1, por lo tanto:
	i = 2*i -1;
	return i;
}

//************************************ARMAR_ARBOL*****************************************//
//La funcion tiene como parámetros un array, un index que se corresponde con el nodo al que
//pertenece el dato y el inicio y fin del array que se esta evaluando
void segmentTree::buildSegmentTree(array <double> d,double index,double init,double final)
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

node & segmentTree::operator[](int pos){
	return tree[pos];
}