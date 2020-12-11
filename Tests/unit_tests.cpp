#include "gtest/gtest.h"
#include "mob_test.h"
#include "attackstrategy_test.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

