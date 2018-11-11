#ifndef ARRAY__H
#define ARRAY__H
#include <iostream>

using namespace std;

#define 		DEFAULT_ALLOC_SIZE			1
#define 		ARRAY_GROWTH_RATE			2

template <class T>
class array {

public:
						array();
						array(int);
						array(const array &);
						~array();
	int 			get_size() const;
	T 				get_value(int pos)const;
	//void 			store(int pos, T data);
	void 			print(ostream &,int);
	void 			push_back(const T &);
	void 			clear();
	T & 			operator[](int);
	const T & operator[](int) const;
	array & 	operator=(const array &);
	bool 			operator==(const array &) const;
	bool 			operator!=(const array &) const;
	template <typename TT>
	friend ostream & operator<<(ostream&,const array<TT>&);
	void 			resize(int new_size);

private:
	T *p;
	int _used_size;
	int _alloc_size;



};

#include "array.cpp"
#endif
