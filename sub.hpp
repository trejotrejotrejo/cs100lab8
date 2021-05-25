#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>
#include <iostream>
#include <sstream>

class Sub : public Base {
        private:
                Base* leftChild = NULL;
                Base* rightChild = NULL;
        public:
                Sub(Base* left, Base* right) {
                        leftChild = left;
                        rightChild = right;
                }
               virtual double evaluate() {
                        return leftChild->evaluate() - rightChild->evaluate();
                }
                virtual std::string stringify() {
                        std::stringstream out;
                        out << leftChild->stringify() << " - " << rightChild->stringify();
                        return out.str();
                }
		virtual int number_of_children() {
			int num = 0;
                        if(leftChild != nullptr)
                                ++num;
                        if(rightChild != nullptr)
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
                                   visitor->visit_sub_begin(this);
                           }
                           else if (index == 1) {
                                   visitor->visit_sub_middle(this);
                           }
                           else if (index == 2) {
                                   visitor->visit_sub_end(this);
                           }
                 }


};

#endif //__SUB_HPP__
