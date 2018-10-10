#ifdef SEGMENT_TREE__H

#include <iostream>
#include "array.hpp"
#include "node.hpp"
#include "dato.hpp"
#include "segmentTree.hpp"

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
	int j = (end-1)/2;

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

int segmentTree::getTreeLength() const{
	return tree.get_size();
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
segmentTree & segmentTree::operator=(const segmentTree &a){
	for(int i = 0; i<a.getTreeLength(); i++){
		tree[i] = a.tree[i];
	}
	return *this;
}

#endif