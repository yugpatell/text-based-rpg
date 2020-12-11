#ifndef __CHARACTER_TEST_HPP__
#define __CHARACTER_TEST_HPP__

#include "../Character/Archer.cpp"
#include "../Character/Knight.cpp"
#include "../Character/Mage.cpp"


TEST(CharacterTest, defaultArcherCharacter){
  Character* char1 = new Archer("Thomas", ARCHER);
  EXPECT_EQ(char1->getMaxHP(), 10);
  EXPECT_EQ(char1->getcurrHP(), 10);
  EXPECT_EQ(char1->getAtk(), 5);
  EXPECT_EQ(char1->getDefense(), 5);
  EXPECT_EQ(char1->getLevel(), 1);
  EXPECT_EQ(char1->getcurrXP(), 0);
  EXPECT_EQ(char1->getMaxXP(), 100);
  EXPECT_TRUE(char1->getcharType() == ARCHER);
  EXPECT_TRUE(char1->getChestplate() == nullptr);
  EXPECT_TRUE(char1->getLeggings() == nullptr);
  EXPECT_TRUE(char1->getWeapon() == nullptr);
}

TEST(CharacterTest, ArcherCharacterLVL2){
  Character* char1 = new Archer("Thomas", ARCHER);
  char1->levelUp();
  EXPECT_EQ(char1->getMaxHP(), 13);
  EXPECT_EQ(char1->getcurrHP(), 13);
  EXPECT_EQ(char1->getAtk(), 10);
  EXPECT_EQ(char1->getDefense(), 7);
  EXPECT_EQ(char1->getLevel(), 2);
  EXPECT_EQ(char1->getMaxXP(), 125);
}

TEST(CharacterTest, defaultKnightCharacter){
  Character* char1 = new Knight("Yug", KNIGHT);
  EXPECT_EQ(char1->getMaxHP(), 10);
  EXPECT_EQ(char1->getcurrHP(), 10);
  EXPECT_EQ(char1->getAtk(), 5);
  EXPECT_EQ(char1->getDefense(), 5);
  EXPECT_EQ(char1->getLevel(), 1);
  EXPECT_EQ(char1->getcurrXP(), 0);
  EXPECT_EQ(char1->getMaxXP(), 100);
  EXPECT_TRUE(char1->getcharType() == KNIGHT);
  EXPECT_TRUE(char1->getChestplate() == nullptr);
  EXPECT_TRUE(char1->getLeggings() == nullptr);
  EXPECT_TRUE(char1->getWeapon() == nullptr);
}

TEST(CharacterTest, KnightCharacterLVL2){
  Character* char1 = new Knight("Yug", KNIGHT);
  char1->levelUp();
  EXPECT_EQ(char1->getMaxHP(), 13);
  EXPECT_EQ(char1->getcurrHP(), 13);
  EXPECT_EQ(char1->getAtk(), 7);
  EXPECT_EQ(char1->getDefense(), 10);
  EXPECT_EQ(char1->getLevel(), 2);
  EXPECT_EQ(char1->getMaxXP(), 125);
}

TEST(CharacterTest, defaultMageCharacter){
  Character* char1 = new Mage("Scott", MAGE);
  EXPECT_EQ(char1->getMaxHP(), 10);
  EXPECT_EQ(char1->getcurrHP(), 10);
  EXPECT_EQ(char1->getAtk(), 5);
  EXPECT_EQ(char1->getDefense(), 5);
  EXPECT_EQ(char1->getLevel(), 1);
  EXPECT_EQ(char1->getcurrXP(), 0);
  EXPECT_EQ(char1->getMaxXP(), 100);
  EXPECT_TRUE(char1->getcharType() == MAGE);
  EXPECT_TRUE(char1->getChestplate() == nullptr);
  EXPECT_TRUE(char1->getLeggings() == nullptr);
  EXPECT_TRUE(char1->getWeapon() == nullptr);
}

TEST(CharacterTest, MageCharacterLVL2){
  Character* char1 = new Mage("Scott", MAGE);
  char1->levelUp();
  EXPECT_EQ(char1->getMaxHP(), 15);
  EXPECT_EQ(char1->getcurrHP(), 15);
  EXPECT_EQ(char1->getAtk(), 8);
  EXPECT_EQ(char1->getDefense(), 7);
  EXPECT_EQ(char1->getLevel(), 2);
  EXPECT_EQ(char1->getMaxXP(), 125);
}

TEST(CharacterTest, CustomCharacter){
  Character* char1 = new Archer("Thomas", ARCHER);
  char1->levelUp();
  char1->levelUp();
  char1->levelUp();
  char1->levelUp();
  char1->setDefense(100);
  char1->setAttack(100);
  char1->setcurrXP(20);
  EXPECT_EQ(char1->getMaxHP(), 22);
  EXPECT_EQ(char1->getcurrHP(), 22);
  EXPECT_EQ(char1->getAtk(), 100);
  EXPECT_EQ(char1->getDefense(), 100);
  EXPECT_EQ(char1->getLevel(), 5);
  EXPECT_EQ(char1->getMaxXP(), 200);
  EXPECT_EQ(char1->getcurrXP(), 20);
}


#endif
