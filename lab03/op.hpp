#ifndef __OP_HPP__
#define __OP_HPP__
   
#include "base.hpp"
#include "../visitor.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

class Op : public Base {
    private:
	double num;
    public:
        Op(double value) : Base() { num = value; }
        double evaluate() { return num; }
        std::string stringify() { 
              std::stringstream out;
              out << num;
              return out.str();        
        }
	int numChildren() {
		return 0;
	}
	Base* get_child(int i) {
		return NULL;
	}
	void accept(Visitor* visitor, int index) {
	        visitor->visit_op(this);
        }


};

#endif //__OP_HPP__

