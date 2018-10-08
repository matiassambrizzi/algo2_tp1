#ifdef ARRAY__H

#include <iostream>
#include <stdio.h>
#include <cassert>
#include "array.hpp"

using namespace std;

template <class T>
array<T>::array(){
	_alloc_size = DEFAULT_ALLOC_SIZE;
	_used_size = 0;
	p = new T[_alloc_size];
}

template <class T>
array<T>::array(int s){
	assert(s>0);
	_used_size = s;
	_alloc_size = s;
	p = new T[s];
}

template <class T>
array<T>::array(const array<T> &c){

	_used_size = c._used_size;
	_alloc_size = c._alloc_size;

	p = new T[_alloc_size];

	for(int i = 0; i<_used_size; ++i){
		p[i] = c.p[i];
	}
}

template <class T>
array<T>::~array(){
	if(p)
		delete []p;
}

template <class T>
T array<T>::get_value(int pos)const{
	assert(pos > 0 || pos < _used_size);
		return p[pos];
}

/*
template <class T>
void array<T>::store(int pos, T data)
{
	if(pos > _alloc_size)
		this -> resize(pos);
	p[pos] = data;
	_used_size = pos+1;
}
*/

template <typename T>
void array<T>::push_back(const T &new_thing)
{
		if(_alloc_size == _used_size)
			this -> resize(_alloc_size * ARRAY_GROWTH_RATE);
		p[_used_size] = new_thing;
		_used_size++;
}


template <class T>
int array<T>::get_size() const
{
	return _used_size;
}

template <class T>
void array<T>::print(ostream &os, int cant)
{
	for(int i = 0;i<cant;i++)
		os << p[i] << endl;
}

template <class T>
void array<T>::resize(int new_size)
{
	T *aux;

	aux = new T[new_size];
	if(new_size < _used_size){
		_used_size = new_size;
	}

	for(int i = 0;i < _used_size;++i)
		aux[i] = p[i];

	delete[]p;

	p = aux;
	_alloc_size = new_size;
}

template <class T>
T & array<T>::operator[](int in)
{
	assert( (0 <= in) && (in < _used_size) ) ;
		return p[ in ];

}

template <class T>
const T & array<T>::operator[](int in) const
{
	assert( (0 <= in) && (in < _used_size) ) ;

		return p[ in ];
}


template <class T>
array<T> & array<T>::operator=(const array<T> &f)
{
	T *aux;
	if ( &f == this ) {
			return *this;
		}

		if ( _alloc_size != f._alloc_size ){
			aux = new T[ f._alloc_size ]();
			delete [] p;
			p = aux;
			_alloc_size = f._alloc_size;
			_used_size = f._used_size;
		}
		_used_size = f._used_size;
		for ( int i = 0; i < _used_size; i++ )
			p[ i ] = f.p[ i ];

		return *this;

}

template <class T>
bool array<T>::operator==(const array<T> &f) const
{
	if(_used_size != f._used_size)
		return false;

	for(int i = 0;i<_used_size;i++)
		if(p[i] != f.p[i])
			return false;

	return true;

}

template <class T>
bool array<T>::operator!=(const array<T> &f) const
{
	if(f == *this)
		return false;
	else
		return true;
}

template <class T>
void array<T>::clear()
{
	if(p)
	{
		delete[] p;
		_alloc_size = DEFAULT_ALLOC_SIZE;
		_used_size = 0;
		p = new T[_alloc_size];
	}
}

template <class T>
ostream & operator<<(ostream &os,const array<T> & arr)
{
	if(arr._used_size == 0)
	{
		os << "";
		return os;
	}

	for (int i = 0;i<(arr._used_size)-1;++i)
	{
		os << arr[i];
		os << ',';
	}
	os << arr[(arr._used_size)-1];

	return os;
}

#endif
