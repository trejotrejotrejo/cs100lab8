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
	double val;
	int num;
    public:
        Op(double value) : Base() { val = value; num = 0; }
        virtual double evaluate() { return val; }
       virtual  std::string stringify() { 
              std::stringstream out;
              out << val;
              return out.str();        
        }
	virtual int numChildren() {
		return num;
	}
	virtual Base* get_child(int i) {
		return NULL;
	}
	virtual void accept(Visitor* visitor, int index) {
	        visitor->visit_op(this);
        }


};

#endif //__OP_HPP__

