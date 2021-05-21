#ifndef __MULT_HPP__
#define __MULT_HPP__
 
 #include "base.hpp"
 #include "op.hpp"
 #include <string>
 #include <iostream>
 
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
                  virtual std::string stringify() {
                          std::stringstream out;
                          out  << leftChild->stringify() << " * " << rightChild->stringify();
                          return out.str();
                  }
 };
 
 #endif //__MULT_HPP__
