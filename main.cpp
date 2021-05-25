
#include "op.hpp"
#include "rand.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "visitor.hpp"
#include "iterator.hpp"
#include <iostream>

int main(){
	Base* val1 = new Op(1);
	Base* val2 = new Op(2);
	Base* val3 = new Op(3);

	Subtract* s1 = new Sub(val2,val1);
	Muliply* m1 = new Mult(val3,val2);
	Divide* d1 = new Div(m1,s1);

	Power* p1 = new Pow(val2, val3);
	Addition* a1 = new Add(val2, val3);
	Subtract* s2 = new Sub(p1,a1);
	
	Addition* add = new Add(d1,s2);
	
	std::cout << add->stringify() << "\n";
	//std::cout << PrintMathML(add) << "\n";

	return 0;
}
