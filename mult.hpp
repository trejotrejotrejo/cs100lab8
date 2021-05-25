#ifndef __MULT_HPP__
#define __MULT_HPP__
 
 #include "base.hpp"
 #include <string>
 #include <iostream>
 #include <sstream>
 
 class Mult : public Base {
          private:
                 Base* leftChild = NULL;
                 Base* rightChild = NULL;
          public:
                  Mult(Base* left, Base* right) {
                          leftChild = left;
                          rightChild = right;
                  }
	          virtual double evaluate() {
                          return leftChild->evaluate() * rightChild->evaluate();
                  }
                   std::string stringify() {
                          std::stringstream out;
                          out  << leftChild->stringify() << " * " << rightChild->stringify();
                          return out.str();
                  }
		virtual int number_of_children() {
           		 int num = 0;
               		if(leftChild!= nullptr)
                       		 ++num;
                	if(rightChild!= nullptr)
                       		 ++num;
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
                                 visitor->visit_mult_begin(this);
                         }
                         else if (index == 1) {
                                 visitor->visit_mult_middle(this);
                         }
                         else if (index == 2) {
                                 visitor->visit_mult_end(this);
                         }
                }

 
};

 #endif //__MULT_HPP__
