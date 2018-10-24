#ifndef NODE__HPP
#define NODE__HPP
#include <iostream>

#include "dato.hpp"

using namespace std;

class node{
public:
				node();
				node(double, double);
				node(double);
				node(node, node);
				node(bool);
				node(dato);
				~node();
	double		getMin();
	double		getMax();
	double		getAddsUp();
	double		getQuantity();
	void		setMin(double);
	void		setMax(double);
	void		setAddsUp(double);
	void		setQuantity(int);
	bool		isNodeUseful();
	void		setNodeUseful(bool);
	node & operator=(const node &);
	node & operator=(const dato &);



private:
	double min, max, addsUp;
	int quantity;
	bool containsData;
};

#endif
