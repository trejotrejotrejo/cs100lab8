#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "visitor.hpp"
#include <string>
#include <iostream>
#include <math.h>
#include <sstream>

class Pow : public Base {
        private:
                Base* leftChild = NULL;
                Base* rightChild = NULL;
        public:
                Pow(Base* left, Base* right) {
                        leftChild = left;
                        rightChild = right;
                }
                virtual double evaluate() {
                        return pow(leftChild->evaluate(), rightChild->evaluate()); 
                }
                virtual std::string stringify() {
                        std::stringstream out;
                        out << leftChild->evaluate() << " ^ " << rightChild->evaluate();
                        return out.str();
                }
		virtual int number_of_children() {
           		int num = 2;
                        return num;
        	}
        	virtual Base* get_child(int i) {
            	  if(i < number_of_children()){
			if(i == 0) {
				return leftChild;
            		}
			else if(i == 1) {
				return rightChild;
			}
            		else return NULL;
        		}
		}
		virtual void accept(Visitor* visitor, int index) {
                          if (index == 0) {
                                  visitor->visit_pow_begin(this);
                          }
                          else if (index == 1) {
                                  visitor->visit_pow_middle(this);
                          }
                          else if (index == 2) {
                                  visitor->visit_pow_end(this);
                          }
                 }


};

#endif //__POW_HPP__
