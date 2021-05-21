

#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>
#include <iostream>
#include <cmath>

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
};

#endif //__POW_HPP__

