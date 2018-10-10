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
				~segmentTree();
	int			treeSize(int);
	int			getTreeLength() const;
	segmentTree & 	operator=(const segmentTree &);

private:
	array <node> tree; 
};

#include "segmentTree.cpp"
#endif
