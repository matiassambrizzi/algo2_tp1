#ifndef SEGMENT_TREE__H
#define SEGMENT_TREE__H

#include <iostream>
#include "node.hpp"
#include "dato.hpp"
#include "array.hpp"

using namespace std;

class segmentTree {

public:
				segmentTree();
				segmentTree(const array <dato>);
				segmentTree(array <double> arr, double quant);
				~segmentTree();
	node			getNode(int);
	int			treeSize(int);
<<<<<<< HEAD
	int			getTreeLength() const;
	segmentTree & 	operator=(const segmentTree &);

private:
	array <node> tree; 
=======
private:
	array <node> tree; //en realidad va a ser del tipo nodo
	//void		initializeSegmentTree(const array <dato>, int);
	void buildSegmentTree(array <double> d,double index,double init,double final);
	//void		buildSegmentTree(array <dato>&,array <dato>, int init, int end)
>>>>>>> 780d5fa51ff6472d083c085052fdcc3fdc09c213
};

#endif
