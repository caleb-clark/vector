#include "Vector.h"
#include <iostream>

int main() 
{
	Vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
		v.print();
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; i++) {
		v.pop_back();
		v.print();
		std::cout << std::endl;
	}
	
	for (int i = 0; i < 10; i++) {
		v.push_front(i);
		v.print();
		std::cout << std::endl;
	}
	
	for (int i = 0; i < 10; i++) {
		v.pop_front();
		v.print();
		std::cout << std::endl;
	}

	for (int i = 0; i < 10; i++) {
		v.push_front(i);
		v.print();
		std::cout << std::endl;
	}



	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " " << v.at(i) << std::endl;
	}
	
	for (int i = 0; i < v.size(); i++) {
		v[i] = i*10;
		v.print();
		std::cout << std::endl;
	}

}
