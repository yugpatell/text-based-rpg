#ifndef __CONSUMABLE_TEST_HPP__
#define __CONSUMABLE_TEST_HPP__

#include "../Consumable/Potion.h"

TEST(ConsumableTest, defaultConsumable) {
  Consumable* consum1 = new Consumable();
  EXPECT_EQ(consum1->getLevel(), 1);
  EXPECT_EQ(consum1->getValue(), 5);
}

TEST(ConsumableTest, customConsumable) {
  Consumable* consum1 = new Consumable(10, 5, "Epic Consumable");
  EXPECT_EQ(consum1->getLevel(), 10);
  EXPECT_EQ(consum1->getValue(), 25);
  EXPECT_EQ(consum1->getName(), "Epic Consumable");
}

TEST(ConsumableTest, defaultPotion){
  Potion* potion1 = new Potion();
  EXPECT_EQ(potion1->getLevel(), 1);
  EXPECT_EQ(potion1->getValue(), 5);
}

TEST(ConsumableTest, customPotion1) {
  Potion* potion1 = new Potion(20, 1, "Poor Potion");
  EXPECT_EQ(potion1->getLevel(), 20);
  EXPECT_EQ(potion1->getValue(), 23);
  EXPECT_EQ(potion1->getName(), "Poor Potion");
}

TEST(ConsumableTest, customPotion2) {
  Potion* potion1 = new Potion(30, 3, "Good Potion");
  EXPECT_EQ(potion1->getLevel(), 30);
  EXPECT_EQ(potion1->getValue(), 39);
  EXPECT_EQ(potion1->getName(), "Good Potion");
}

#endif
