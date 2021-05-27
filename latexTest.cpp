#include "add.hpp"
#include "op.hpp"
#include "base.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "iterator.hpp"
#include "visitor.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
using namespace std;

TEST(LatexTest, addTest) {
	Base* val1 = new Op(1);
	Base* val2 = new Op(2);

	Add* add = new Add(val1, val2);
	Iterator* it = new Iterator(add);

    	VisitorLaTeX* v = new VisitorLaTeX();
	for(it; !it->is_done(); it->next()){
		it->current_node()->accept(v,it->current_index());
	}

	EXPECT_EQ(v->getString(), "${({1.000000}+{2.000000})}$");
}

TEST(LatexTest, subTest){
        Base* val1 = new Op(8);
        Base* val2 = new Op(3);

        Sub* sub = new Sub(val1, val2);
        Iterator* it = new Iterator(sub);

        VisitorLaTeX* v = new VisitorLaTeX();
        for(it; !it->is_done(); it->next()){
                it->current_node()->accept(v,it->current_index());
        }
        EXPECT_EQ(v->getString(), "${({8.000000}-{3.000000})}$");

}

TEST(LatexTest, multTest){
        Base* val1 = new Op(3);
        Base* val2 = new Op(4);

        Mult* mult = new Mult(val1, val2);
        Iterator* it = new Iterator(mult);

        VisitorLaTeX* v = new VisitorLaTeX();
        for(it; !it->is_done(); it->next()){
                it->current_node()->accept(v,it->current_index());
        }

        EXPECT_EQ(v->getString(), "${({3.000000}\\cdot{4.000000})}$");

}

TEST(LatexTest, divTest){
        Base* val1 = new Op(12);
        Base* val2 = new Op(6);

        Div* div = new Div(val1, val2);
        Iterator* it = new Iterator(div);

        VisitorLaTeX* v = new VisitorLaTeX();
        for(it; !it->is_done(); it->next()){
                it->current_node()->accept(v,it->current_index());
        }

        EXPECT_EQ(v->getString(), "${\\frac{12.000000}{6.000000}}$");

}

TEST(LatexTest, powTest){
        Base* val1 = new Op(3);
        Base* val2 = new Op(2);

        Pow* pow = new Pow(val1, val2);
        Iterator* it = new Iterator(pow);

        VisitorLaTeX* v = new VisitorLaTeX();
        for(it; !it->is_done(); it->next()){
                it->current_node()->accept(v,it->current_index());
        }

        EXPECT_EQ(v->getString(), "${({3.000000}^{2.000000})}$");

}

TEST(LatexTest, treeTest){
        Base* val1 = new Op(1);
    	Base* val2 = new Op(2);
    	Base* val3 = new Op(3);

    	Sub* s1 = new Sub(val2, val1);
    	Mult* m1 = new Mult(val3, val2);
    	Div* d1 = new Div(m1, s1);

    	Pow* p1 = new Pow(val2, val3);

    	Add* add = new Add(d1, p1);
       
        Iterator* it = new Iterator(add);

        VisitorLaTeX* v = new VisitorLaTeX();
        for(it; !it->is_done(); it->next()){
                it->current_node()->accept(v,it->current_index());
        }

        EXPECT_EQ(v->getString(), "${({\\frac{({3.000000}\\cdot{2.000000})}{({2.000000}-{1.000000})}}+{({2.000000}^{3.000000})})}$");
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
