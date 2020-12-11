#ifndef __CHARACTER_TEST_HPP__
#define __CHARACTER_TEST_HPP__

#include "../Character/Archer.cpp"
#include "../Character/Knight.cpp"
#include "../Character/Mage.cpp"

TEST(CharacterTest, defaultArcherCharacter){
  Character* char2 = new Archer("Thomas", ARCHER);
  EXPECT_EQ(char2->getMaxHP(), 10);
  EXPECT_EQ(char2->getcurrHP(), 10);
  EXPECT_EQ(char2->getAtk(), 5);
  EXPECT_EQ(char2->getDefense(), 5);
  EXPECT_EQ(char2->getLevel(), 1);
  EXPECT_EQ(char2->getcurrXP(), 0);
  EXPECT_EQ(char2->getMaxXP(), 100);
  EXPECT_TRUE(char2->getcharType() == ARCHER);
  EXPECT_TRUE(char2->getChestplate() == nullptr);
  EXPECT_TRUE(char2->getLeggings() == nullptr);
  EXPECT_TRUE(char2->getWeapon() == nullptr);
}

TEST(CharacterTest, ArcherCharacterLVL2){
  Character* char3 = new Archer("Jesus", ARCHER);
  char3->setcurrXP(100);
  char3->levelUp();
  EXPECT_EQ(char3->getMaxHP(), 13);
  EXPECT_EQ(char3->getcurrHP(), 13);
  EXPECT_EQ(char3->getAtk(), 10);
  EXPECT_EQ(char3->getDefense(), 7);
  EXPECT_EQ(char3->getLevel(), 2);
  EXPECT_EQ(char3->getMaxXP(), 125);
}

TEST(CharacterTest, defaultKnightCharacter){
  Character* char4 = new Knight("Yug", KNIGHT);
  EXPECT_EQ(char4->getMaxHP(), 10);
  EXPECT_EQ(char4->getcurrHP(), 10);
  EXPECT_EQ(char4->getAtk(), 5);
  EXPECT_EQ(char4->getDefense(), 5);
  EXPECT_EQ(char4->getLevel(), 1);
  EXPECT_EQ(char4->getcurrXP(), 0);
  EXPECT_EQ(char4->getMaxXP(), 100);
  EXPECT_TRUE(char4->getcharType() == KNIGHT);
  EXPECT_TRUE(char4->getChestplate() == nullptr);
  EXPECT_TRUE(char4->getLeggings() == nullptr);
  EXPECT_TRUE(char4->getWeapon() == nullptr);
}

TEST(CharacterTest, KnightCharacterLVL2){
  Character* char5 = new Knight("Jesus2", KNIGHT);
  char5->setcurrXP(100);
  char5->levelUp();
  EXPECT_EQ(char5->getMaxHP(), 13);
  EXPECT_EQ(char5->getcurrHP(), 13);
  EXPECT_EQ(char5->getAtk(), 7);
  EXPECT_EQ(char5->getDefense(), 10);
  EXPECT_EQ(char5->getLevel(), 2);
  EXPECT_EQ(char5->getMaxXP(), 125);
}

TEST(CharacterTest, defaultMageCharacter){
  Character* char6 = new Mage("Scott", MAGE);
  EXPECT_EQ(char6->getMaxHP(), 10);
  EXPECT_EQ(char6->getcurrHP(), 10);
  EXPECT_EQ(char6->getAtk(), 5);
  EXPECT_EQ(char6->getDefense(), 5);
  EXPECT_EQ(char6->getLevel(), 1);
  EXPECT_EQ(char6->getcurrXP(), 0);
  EXPECT_EQ(char6->getMaxXP(), 100);
  EXPECT_TRUE(char6->getcharType() == MAGE);
  EXPECT_TRUE(char6->getChestplate() == nullptr);
  EXPECT_TRUE(char6->getLeggings() == nullptr);
  EXPECT_TRUE(char6->getWeapon() == nullptr);
}

TEST(CharacterTest, MageCharacterLVL2){
  Character* char7 = new Mage("Jesus3", MAGE);
  char7->setcurrXP(100);
  char7->levelUp();
  EXPECT_EQ(char7->getMaxHP(), 15);
  EXPECT_EQ(char7->getcurrHP(), 15);
  EXPECT_EQ(char7->getAtk(), 8);
  EXPECT_EQ(char7->getDefense(), 7);
  EXPECT_EQ(char7->getLevel(), 2);
  EXPECT_EQ(char7->getMaxXP(), 125);
}

TEST(CharacterTest, CustomCharacter){
  Character* char8 = new Archer("Jesus4", ARCHER);
  char8->setcurrXP(100);
  char8->levelUp();
  char8->setcurrXP(125);
  char8->levelUp();
  char8->setcurrXP(150);
  char8->levelUp();
  char8->setcurrXP(175);
  char8->levelUp();
  char8->setDefense(100);
  char8->setAttack(100);
  EXPECT_EQ(char8->getMaxHP(), 22);
  EXPECT_EQ(char8->getcurrHP(), 22);
  EXPECT_EQ(char8->getAtk(), 125);
  EXPECT_EQ(char8->getDefense(), 113);
  EXPECT_EQ(char8->getLevel(), 5);
  EXPECT_EQ(char8->getMaxXP(), 200);
  EXPECT_EQ(char8->getcurrXP(), 0);

}


#endif
