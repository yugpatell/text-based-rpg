#ifndef __WEAPON_TEST_HPP__
#define __WEAPON_TEST_HPP__

#include "../Equipable/Sword.h"
#include "../Equipable/Staff.h"
#include "../Equipable/Bow.h"

TEST(WeaponTest, defaultWeapon) {
  Weapon* weapon1 = new Weapon();
  EXPECT_EQ(weapon1->getLevel(), 1);
  EXPECT_EQ(weapon1->getValue(), 5);
  EXPECT_EQ(weapon1->getRole(), 0);
  EXPECT_TRUE(!weapon1->isArmor());
}

TEST(WeaponTest, customWeapon) {
  Weapon* weapon1 = new Weapon(10, 3, 0);
  EXPECT_EQ(weapon1->getLevel(), 10);
  EXPECT_EQ(weapon1->getValue(), 19);
  EXPECT_EQ(weapon1->getRole(), 0);
  EXPECT_TRUE(!weapon1->isArmor());
}

TEST(WeaponTest, defaultSword) {
  Sword* weapon1 = new Sword();
  EXPECT_EQ(weapon1->getLevel(), 1);
  EXPECT_EQ(weapon1->getValue(), 5);
  EXPECT_EQ(weapon1->getRole(), 0);
  EXPECT_TRUE(!weapon1->isArmor());
  EXPECT_EQ(weapon1->getName(), " ");
}

TEST(WeaponTest, customSword) {
  Sword* weapon1 = new Sword(4, 4, "Rare Sword");
  EXPECT_EQ(weapon1->getLevel(), 4);
  EXPECT_EQ(weapon1->getValue(), 16);
  EXPECT_EQ(weapon1->getRole(), 0);
  EXPECT_TRUE(!weapon1->isArmor());
  EXPECT_EQ(weapon1->getName(), "Rare Sword");
}

TEST(WeaponTest, defaultStaff) {
  Staff* weapon1 = new Staff();
  EXPECT_EQ(weapon1->getLevel(), 1);
  EXPECT_EQ(weapon1->getValue(), 5);
  EXPECT_EQ(weapon1->getRole(), 1);
  EXPECT_TRUE(!weapon1->isArmor());
  EXPECT_EQ(weapon1->getName(), " ");
}

TEST(WeaponTest, customStaff) {
  Staff* weapon1 = new Staff(5, 3, "Good Staff");
  EXPECT_EQ(weapon1->getLevel(), 5);
  EXPECT_EQ(weapon1->getValue(), 14);
  EXPECT_EQ(weapon1->getRole(), 1);
  EXPECT_TRUE(!weapon1->isArmor());
  EXPECT_EQ(weapon1->getName(), "Good Staff");
}

TEST(WeaponTest, defaultBow) {
  Bow* weapon1 = new Bow();
  EXPECT_EQ(weapon1->getLevel(), 1);
  EXPECT_EQ(weapon1->getValue(), 5);
  EXPECT_EQ(weapon1->getRole(), 2);
  EXPECT_TRUE(!weapon1->isArmor());
  EXPECT_EQ(weapon1->getName(), " ");
}

TEST(WeaponTest, customBow) {
  Bow* weapon1 = new Bow(7, 1, "Poor Bow");
  EXPECT_EQ(weapon1->getLevel(), 7);
  EXPECT_EQ(weapon1->getValue(), 10);
  EXPECT_EQ(weapon1->getRole(), 2);
  EXPECT_TRUE(!weapon1->isArmor());
  EXPECT_EQ(weapon1->getName(), "Poor Bow");
}


#endif
