#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"
#include "op.hpp"
#include <string>
#include <iostream>

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
};

#endif //__SUB_HPP__
