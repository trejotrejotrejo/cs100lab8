#include "gtest/gtest.h"
#include "lab03/base.hpp"
#include "lab03/op.hpp"
#include "lab03/mult.hpp"
#include "lab03/add.hpp"
#include "lab03/sub.hpp"
#include "lab03/pow.hpp"
#include "lab03/rand.hpp"
#include "lab03/div.hpp"
#include <iostream>
#include "iterator.hpp"
#include "visitor.hpp"

using namespace std;
  
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
