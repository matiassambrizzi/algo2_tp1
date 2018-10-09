#ifdef NODO__H

#include <iostream>
#include "array.hpp"
#include "dato.hpp"
	
nodo::nodo(){
	min = 0; max = 0; addsUp = 0; quantity = 0;
	containsData = false;
}

nodo(double a, double b){
	min = a;
	max = b;
	addsUp = a + b;
	quantity = 2;
	containsData = true;
}

nodo(node a, node b){
	if(a.isNodeUseful() == false && b.isNodeUseful() == false){
		min = 0; max = 0; addsUp = 0; quantity = 0;
		containsData = true;
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
		if(a.min =< b.min){
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


node(bool useful){
	isNodeUseful = useful;
}


~nodo(){
}

double nodo::getMin(){
	return min;
}
double nodo::getMax(){
	return max;
}
double nodo::getAddsUp(){
	return addsUp;
}
double nodo::getQuantity(){
	return quantity;
}
void nodo::setMin(double a){
	min = a;
}
void nodo::setMax(double a){
	max = a;
}
void setAddsUp(double a){
	addsUp = a;
}
void setQuantity(int a){
	quantity = a;
}
bool isNodeUseful(){
	return containsData;
}
void setNodeUseful(bool useful){
	containsData = useful;
}


#endif