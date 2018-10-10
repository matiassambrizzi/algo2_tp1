#ifndef DATO__H
#define DATO__H
#include <iostream>

using namespace std;

class dato {
public:
					dato();
					dato(double, bool);
					dato(double);
					~dato();
	double 			get_dato() const;
	bool			dato_available()const;
	void 			set_dato(double);
	void			set_availability(bool);		
	friend ostream& operator<<(ostream&,const dato &);
	bool 			operator==(const dato &);
	bool 			operator!=(const dato &);
	bool 			operator<(const double &);
	bool 			operator>(const double &);
	bool 			operator<=(const double &);
	bool 			operator>=(const double &);	
	
private:
	double 			measure;
	bool 			exists;
};

#include "dato.cpp"
#endif
