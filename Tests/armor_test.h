#ifndef __ARMOR_TEST_HPP__
#define __ARMOR_TEST_HPP__

#include "../Equipable/Armor.h"
#include "../Equipable/ArmoredLeggings.h"
#include "../Equipable/Chainmail.h"
#include "../Equipable/Chestplate.h"
#include "../Equipable/LeatherPants.h"
#include "../Equipable/Robe.h"
#include "../Equipable/SilkPants.h"

TEST(ArmorTest, defaultArmor) {
  Armor* armor1 = new Armor();
  EXPECT_TRUE(!armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 1);
  EXPECT_EQ(armor1->getValue(), 5);
  EXPECT_EQ(armor1->getRole(), 0);
}

TEST(ArmorTest, customArmor) {
  Armor* armor1 = new Armor(10, 3, 0, 1);
  EXPECT_TRUE(armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 10);
  EXPECT_EQ(armor1->getValue(), 19);
  EXPECT_EQ(armor1->getRole(), 0);
}

TEST(ArmorTest, defaultArmoredLeggings) {
  ArmoredLeggings* armor1 = new ArmoredLeggings();
  EXPECT_TRUE(armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 1);
  EXPECT_EQ(armor1->getValue(), 5);
  EXPECT_EQ(armor1->getRole(), 0);
  EXPECT_EQ(armor1->getName(), " ");
}

TEST(ArmorTest, customArmoredLeggings) {
  ArmoredLeggings* armor1 = new ArmoredLeggings(5, 1, "Bad Armored Leggings");
  EXPECT_TRUE(armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 5);
  EXPECT_EQ(armor1->getValue(), 8);
  EXPECT_EQ(armor1->getRole(), 0);
  EXPECT_EQ(armor1->getName(), "Bad Armored Leggings");
}

TEST(ArmorTest, defaultChestplate) {
  Chestplate* armor1 = new Chestplate();
  EXPECT_TRUE(!armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 1);
  EXPECT_EQ(armor1->getValue(), 5);
  EXPECT_EQ(armor1->getRole(), 0);
  EXPECT_EQ(armor1->getName(), " ");
}

TEST(ArmorTest, customChestplate) {
  Chestplate* armor1 = new Chestplate(3, 3, "Good Chestplate");
  EXPECT_TRUE(!armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 3);
  EXPECT_EQ(armor1->getValue(), 12);
  EXPECT_EQ(armor1->getRole(), 0);
  EXPECT_EQ(armor1->getName(), "Good Chestplate");
}

TEST(ArmorTest, defaultLeatherPants) {
  LeatherPants* armor1 = new LeatherPants();
  EXPECT_TRUE(armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 1);
  EXPECT_EQ(armor1->getValue(), 5);
  EXPECT_EQ(armor1->getRole(), 2);
  EXPECT_EQ(armor1->getName(), " ");
}

TEST(ArmorTest, customLeatherPants) {
  LeatherPants* armor1 = new LeatherPants(3, 1, "Poor Leather Pants");
  EXPECT_TRUE(armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 3);
  EXPECT_EQ(armor1->getValue(), 6);
  EXPECT_EQ(armor1->getRole(), 2);
  EXPECT_EQ(armor1->getName(), "Poor Leather Pants");
}

TEST(ArmorTest, defaultChainmail) {
  Chainmail* armor1 = new Chainmail();
  EXPECT_TRUE(!armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 1);
  EXPECT_EQ(armor1->getValue(), 5);
  EXPECT_EQ(armor1->getRole(), 2);
  EXPECT_EQ(armor1->getName(), " ");
}

TEST(ArmorTest, customChainmail) {
  Chainmail* armor1 = new Chainmail(4, 2, "Fair Chainmail");
  EXPECT_TRUE(!armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 4);
  EXPECT_EQ(armor1->getValue(), 10);
  EXPECT_EQ(armor1->getRole(), 2);
  EXPECT_EQ(armor1->getName(), "Fair Chainmail");
}

TEST(ArmorTest, defaultSilkPants) {
  SilkPants* armor1 = new SilkPants();
  EXPECT_TRUE(armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 1);
  EXPECT_EQ(armor1->getValue(), 5);
  EXPECT_EQ(armor1->getRole(), 1);
  EXPECT_EQ(armor1->getName(), " ");
}

TEST(ArmorTest, customSilkPants) {
  SilkPants* armor1 = new SilkPants(2, 4, "Rare Silk Pants");
  EXPECT_TRUE(armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 2);
  EXPECT_EQ(armor1->getValue(), 14);
  EXPECT_EQ(armor1->getRole(), 1);
  EXPECT_EQ(armor1->getName(), "Rare Silk Pants");
}

TEST(ArmorTest, defaultRobe) {
  Robe* armor1 = new Robe();
  EXPECT_TRUE(!armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 1);
  EXPECT_EQ(armor1->getValue(), 5);
  EXPECT_EQ(armor1->getRole(), 1);
  EXPECT_EQ(armor1->getName(), " ");
}

TEST(ArmorTest, customRobe) {
  Robe* armor1 = new Robe(10, 1, "Poor Robe");
  EXPECT_TRUE(!armor1->getChestOrPants());
  EXPECT_EQ(armor1->getLevel(), 10);
  EXPECT_EQ(armor1->getValue(), 13);
  EXPECT_EQ(armor1->getRole(), 1);
  EXPECT_EQ(armor1->getName(), "Poor Robe");
}

#endif
