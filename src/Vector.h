#include <iostream>

typedef unsigned int UInt32;

template <class T>
class Vector 
{
private:
	friend class Vector;
	// ptr to data
	T * arr;
	// current capacity of the underlying array
	UInt32 cap;
	// current size of the vector
	UInt32 sz;
public:

	// constructor
	Vector(UInt32 initial_cap = 1);
	// destructor
	~Vector();
	// copy constructor
	Vector(const Vector& v);
	// copy assignment operator overload
	Vector& operator=(const Vector& v);
	// insert element at back
	void push_back(T t);
	// remove last element and return copy
	T pop_back();
	// insert element at front
	void push_front(T t);
	// remove first element and return copy
	T pop_front();
	// returns the size of the vector
	UInt32 size();
	// returns the element at the given position
	T& at(UInt32 pos);
	// returns the element at the given position
	T& operator[](UInt32 pos);
	// prints the contents of the vector
	void print();
};


// constructor
template <class T> 
Vector<T>::Vector(UInt32 initial_cap)
{
	arr = new T[initial_cap];
	cap = initial_cap;
	sz  = 0;
}

// destructor
template <class T> 
Vector<T>::~Vector()
{
	delete arr;
}

// copy constructor
template <class T> 
Vector<T>::Vector(const Vector& v)
{
	this->cap = v.cap;
	this->sz  = v.sz;
	this->arr = new T[cap];

	for (UInt32 i = 0; i < this->sz; i++) {
		arr[i] = v.at(i);
	}
}

// copy assignment operator overload
template <class T> 
Vector<T>& Vector<T>::operator=(const Vector& v)
{
	this->cap = v.cap;
	this->sz  = v.sz;
	delete arr;
	arr = new T[cap];

	for (UInt32 i = 0; i < this->sz; i++) {
		arr[i] = v.at(i);
	}

}

// insert element at back
template <class T> 
void Vector<T>::push_back(T t)
{
	if (sz < cap) {
		arr[sz] = t;
		sz++;
	} else if (sz == cap) {
		cap *= 2;
		T * tmp = arr;
		arr = new T[cap];
		UInt32 i = 0;
		for (; i < sz; i++) {
			arr[i] = tmp[i];
		}
		delete tmp;
		arr[i] = t;
		sz++;
	}
}

// remove last element and return copy
template <class T> 
T Vector<T>::pop_back()
{
	if (sz > 0) {
		sz--;
		return arr[sz];
	} else {
		return T();
	}
}

// insert element at front
template <class T> 
void Vector<T>::push_front(T t)
{
	if (sz < cap) {
		for (UInt32 i = sz; i > 0; i--) {
			arr[i] = arr[i-1];
		}
		arr[0] = t;
		sz++;
	} else if (sz == cap) {
		T * tmp = arr;
		arr = new T[cap*2];
		cap *= 2;

		for (UInt32 i = sz; i > 0; i--) {
			arr[i] = tmp[i-1];
		}
		delete tmp;
		arr[0] = t;
		sz++;
	}
}

// remove first element and return copy
template <class T> 
T Vector<T>::pop_front()
{
	if (sz > 0) {
		T * tmp = arr;
		T to_return = arr[0];
		for (UInt32 i = 0; i < (sz - 1); i++) {
			arr[i] = arr[i+1];
		}
		sz--;
		return to_return;
	} else {
		return T();
	}
}

// returns the size of the vector
template <class T> 
UInt32 Vector<T>::size()
{
	return sz;
}

// returns the element at the given position
template <class T> 
T& Vector<T>::at(UInt32 pos)
{
	if (pos < sz) {
		return arr[pos];
	} else {
		return T();
	}
}

// returns the element at the given position
template <class T> 
T& Vector<T>::operator[](UInt32 pos)
{
	return at(pos);
}

// prints the contents of the vector
template <class T>
void Vector<T>::print()
{
	for (UInt32 i = 0; i < sz; i++) {
		std::cout << arr[i] << " ";
	}
}