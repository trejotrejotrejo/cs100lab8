#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
#include <string>
#include <iostream>

class Rand: public Base {
	private:
		double num;
    public:
        Rand() { num = rand() % 100; }
        virtual double evaluate() { return num; }
        virtual std::string stringify() { return std::to_string(num);}	
	int number_of_children() { 	
		return 0; 
	}
        Base* get_child(int i) { 
		return this; 
	}
	void accept(Visitor* visitor, int index) {
		visitor->visit_rand(this);
	}

};

#endif //__RAND_HPP__
