#ifndef __DIV_HPP__
#define __DIV_HPP__
 
 #include "base.hpp"
 #include "op.hpp"
 #include <string>
 #include <iostream>
 
 class Div : public Base {
          private:
                 Base* leftChild = NULL;
                 Base* rightChild = NULL;
          public:
                  Div(Base* left, Base* right) {
                          leftChild = left;
                          rightChild = right;
                  }
                  virtual double evaluate() {
                          return leftChild->evaluate() / rightChild->evaluate();
                  }
                  virtual std::string stringify() {
                          std::stringstream out;
                          out  << leftChild->stringify() << " / " << rightChild->stringify();
                          return out.str();
                  }
		int number_of_children() {
            		return 2;
        	}
        	Base* get_child(int i) {
           		 if(i == 0) {
				return leftChild;
			 }
                         else if(i == 1) {
		                return rightChild;
	                 }
                         else return NULL;
                }


 };
 
 #endif //__DIV_HPP__
