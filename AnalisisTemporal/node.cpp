
#include <iostream>
#include "array.hpp"
#include "dato.hpp"
#include "node.hpp"

node::node(){
	min = 0; max = 0; addsUp = 0; quantity = 0;
	containsData = false;
}

node::node(double a, double b){
	min = a;
	max = b;
	addsUp = a + b;
	quantity = 2;
	containsData = true;
}

node::node(double a){

		min = a;
		max = min;
		addsUp = min;
		quantity = 1;
		containsData = true;

}

node::node(dato a){
	if(a.dato_available() == true){
		min = a.get_dato();
		max = min;
		addsUp = min;
		quantity = 1;
		containsData = true;
	}
	else{
		min = 0; max = 0; addsUp = 0; quantity = 0;
		containsData = false;
	}
}

node::node(node a, node b){
	if(a.isNodeUseful() == false && b.isNodeUseful() == false){
		min = 0; max = 0; addsUp = 0; quantity = 0;
		containsData = false;
	}
	else if(a.isNodeUseful() == false && b.isNodeUseful() == true){
		min = b.min;
		max = b.max;
		addsUp = b.addsUp;
		quantity = b.quantity;
		containsData = true;
	}
	else if(a.isNodeUseful() == true && b.isNodeUseful() == false){
		min = a.min;
		max = a.max;
		addsUp = a.addsUp;
		quantity = a.quantity;
		containsData = true;
	}
	else{
		if(a.min <= b.min){
			min = a.min;
		}
		else{
			min = b.min;
		}
		if(a.max >= b.max){
			max = a.max;
		}
		else{
			max = b.max;
		}
		addsUp = a.addsUp + b.addsUp;
		quantity = a.quantity + b.quantity;
		containsData = true;
	}
}


node::node(bool useful){
	containsData = useful;
}

node& node::operator=(const node & a){
	min = a.min;
	max = a.max;
	quantity = a.quantity;
	addsUp = a.addsUp;
	containsData = a.containsData;
	return *this;
}

node& node::operator=(const dato & a){
	if(a.dato_available() == true){
		min = a.get_dato();
		max = min;
		addsUp = min;
		quantity = 1;
		containsData = true;
	}
	else{
	min = 0; max = 0; addsUp = 0; quantity = 0;
	containsData = false;
	}
	return *this;
}

node::~node(){
}

double node::getMin(){
	return min;
}
double node::getMax(){
	return max;
}
double node::getAddsUp(){
	return addsUp;
}
double node::getQuantity(){
	return quantity;
}
void node::setMin(double a){
	min = a;
}
void node::setMax(double a){
	max = a;
}
void node::setAddsUp(double a){
	addsUp = a;
}
void node::setQuantity(int a){
	quantity = a;
}
bool node::isNodeUseful(){
	return containsData;
}
void node::setNodeUseful(bool useful){
	containsData = useful;
}

ostream & operator<<(ostream &os,const node & n)
{
	if(n.containsData == true){
		os<<n.addsUp/n.quantity;
		os<<DELIM;
		os<<n.min;
		os<<DELIM;
		os<<n.max;
		os<<DELIM;
		os<<n.quantity;
		os<<endl;
	}else{
		os<<NO_DATA_MSG<<endl;
	}

	return os;
}
