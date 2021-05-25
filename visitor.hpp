#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

#include <iostream>
#include <string>

class Op;
class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

class Visitor{
    public:
        virtual ~Visitor() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(Op* node) = 0;
        virtual void visit_rand(Rand* node) = 0;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(Add* node) = 0;
        virtual void visit_add_middle(Add* node) = 0;
        virtual void visit_add_end(Add* node) = 0;
        virtual void visit_sub_begin(Sub* node) = 0;
        virtual void visit_sub_middle(Sub* node) = 0;
        virtual void visit_sub_end(Sub* node) = 0;
        virtual void visit_mult_begin(Mult* node) = 0;
        virtual void visit_mult_middle(Mult* node) = 0;
        virtual void visit_mult_end(Mult* node) = 0;
        virtual void visit_div_begin(Div* node) = 0;
        virtual void visit_div_middle(Div* node) = 0;
        virtual void visit_div_end(Div* node) = 0;
        virtual void visit_pow_begin(Pow* node) = 0;
        virtual void visit_pow_middle(Pow* node) = 0;
        virtual void visit_pow_end(Pow* node) = 0;
};

class VisitorLaTeX : public Visitor {
    private:
	std::string str;
	
	
    public:
	VisitorLaTeX();

	std::string getString();
        virtual void visit_op(Op* node);
        virtual void visit_rand(Rand* node);

	virtual void visit_add_begin(Add* node);
        virtual void visit_add_middle(Add* node);
        virtual void visit_add_end(Add* node);
        virtual void visit_sub_begin(Sub* node);
        virtual void visit_sub_middle(Sub* node);
        virtual void visit_sub_end(Sub* node);
        virtual void visit_mult_begin(Mult* node);
        virtual void visit_mult_middle(Mult* node);
        virtual void visit_mult_end(Mult* node);
        virtual void visit_div_begin(Div* node);
        virtual void visit_div_middle(Div* node);
        virtual void visit_div_end(Div* node);
        virtual void visit_pow_begin(Pow* node);
        virtual void visit_pow_middle(Pow* node);
        virtual void visit_pow_end(Pow* node);
};

#endif //__VISITOR_HPP__
