#ifndef __ADD_HPP__
#define __ADD_HPP__
 
 #include "base.hpp"
 #include "visitor.hpp"
 #include <string>
 #include <iostream>
 
 class Add : public Base {
          private:
                 Base* leftChild = NULL;
                 Base* rightChild = NULL;
          public:
                  Add(Base* left, Base* right) {
                          leftChild = left;
                          rightChild = right;
                  }
                 virtual double evaluate() {
                          return leftChild->evaluate() + rightChild->evaluate();
                  }
                  virtual std::string stringify() {
                          std::stringstream out;
                          out  << leftChild->stringify() << " + " << rightChild->stringify();
                          return out.str();
                  }
	         virtual int numChildren() {
			return 2;
		 }
		 virtual Base* get_child(int i) {
			if(i == 0) {
				return leftChild;
			}
			else if (i == 1) {
				return rightChild;
			}
			else return NULL;
		 }
		virtual void accept(Visitor* visitor, int index) {
			if (index == 0) {
				visitor->visit_add_begin(this);
			}
			else if (index == 1) {
				visitor->visit_add_middle(this);
			}
			else if (index == 2) {
				visitor->visit_add_end(this);
			}
			}
};  
 #endif //__ADD_HPP__
