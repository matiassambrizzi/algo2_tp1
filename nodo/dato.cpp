#include <iostream>
#include "dato.hpp"

using namespace std;

dato::dato(){
	measure = 0;
	exists = false;
}

dato::dato(double d, bool e){
	measure = d;
	exists = e;
}

dato::dato(double d){
	measure = d;
	exists = true;
}

dato::~dato(){
}

bool dato::dato_available(){
	return exists;
}

double dato::get_dato(){
	//if(this->data_available() == true)
		return this->measure;
	//else
	//	oss
}



void dato::set_dato(double d){
	measure = d;
}

void dato::set_availability(bool e){
	exists = e;
}

ostream& operator<<(ostream &os,const dato &d){
	if (d.exists == true){
		os<<d.measure;
	} else{
		os<<"Invalid Value";
	}
	return os;
}

bool dato::operator==(const dato &f){
	if(f.measure == this->measure && f.exists == this->exists){
		return true;
	}
	else {
		return false;
	}
}
bool dato::operator!=(const dato &f){
	if(f.measure == this->measure && f.exists == this->exists){
		return false;
	}
	else {
		return true;
	}
}

bool dato::operator<(const double &f){
	if(f > this->measure){
		return true;
	}else{
		return false;
	}
}

bool dato::operator>(const double &f){
	if(f < this->measure){
		return true;
	}else{
		return false;
	}
}

bool dato::operator>=(const double &f){
	if(f <= this->measure){
		return true;
	}else{
		return false;
	}
}

bool dato::operator<=(const double &f){
	if(f >= this->measure){
		return true;
	}else{
		return false;
	}
}