#ifndef SEGMENT_TREE__H
#define SEGMENT_TREE__H
#include <iostream>
#include "node.hpp"
#include "dato.hpp"
using namespace std;

class segmentTree {

public:
				segmentTree();
				segmentTree(const array <dato>);
				~segmentTree();
	int			treeSize(int);
private:
	array <node> tree; //en realidad va a ser del tipo nodo
	//void		initializeSegmentTree(const array <dato>, int);

	//void		buildSegmentTree(array <dato>&,array <dato>, int init, int end)
};

#include "segmentTree.cpp"
#endif
