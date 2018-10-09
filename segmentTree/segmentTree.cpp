#ifdef SEGMENT_TREE__H

#include <iostream>
#include "array.hpp"
#include "sensor.hpp"
#include "node.hpp"
#include "dato.hpp"

segmentTree::segmentTree(){
}

segmentTree::segmentTree(const array <dato> d){
	int lengthTree = this->treeSize(d.get_size());
	array <node> tree(lengthTree);
	int start = (lengthTree+1)/2-1;
	for(int i = start; i < lengthTree; i++){
		tree[start] = d[start];
	}

	int end = start;
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
*/
#endif