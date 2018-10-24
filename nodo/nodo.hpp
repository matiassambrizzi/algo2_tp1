#ifndef NODO__HPP
#define NODO__HPP

#include <iostream>

using namespace std;

class nodo {

public:
						nodo();
						nodo(double, double);
						nodo(nodo, nodo);
						nodo(bool);
						~nodo();
	double		getMin();
	double		getMax();
	double		getAddsUp();
	double		getQuantity();
	void		setMin(double);
	void		setMax(double);
	void		setAddsUp(double);
	void		setQuantity(int);
	bool		isNodeUseful();
	void		setNodeUseful();

private:
	double min, max, addsUp;
	int quantity;
	bool containsData;
};

#endif
