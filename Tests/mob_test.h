#ifndef __MOB_TEST_HPP__
#define __MOB_TEST_HPP__

#include "../Mob/drake.h"
#include "../Mob/troll.h"
#include "../Mob/wolf.h"
#include "../Mob/yeti.h"

TEST(MobTest, DrakeLv1) {
  Drake* drake1 = new Drake(1);
  EXPECT_EQ(drake1->get_mob_hp(), 3);
  EXPECT_EQ(drake1->get_mob_atk(), 3);
  EXPECT_EQ(drake1->get_mob_def(), 2);
  EXPECT_NEAR(drake1->get_mob_lvl(), 1, 3); //random
  EXPECT_NEAR(drake1->get_mob_exp(), 15, 45); //random
  EXPECT_EQ(drake1->getName(), "DRAKE");
  EXPECT_NEAR(drake1->attackChar(5), 2, 1); //random
}

TEST(MobTest, TrollLv1) {
  Troll* troll1 = new Troll(1);
  EXPECT_EQ(troll1->get_mob_hp(), 2);
  EXPECT_EQ(troll1->get_mob_atk(), 2);
  EXPECT_EQ(troll1->get_mob_def(), 4);
  EXPECT_NEAR(troll1->get_mob_lvl(), 1, 3); //random
  EXPECT_NEAR(troll1->get_mob_exp(), 5, 15); //random
  EXPECT_EQ(troll1->getName(), "TROLL");
  EXPECT_NEAR(troll1->attackChar(5), 2, 1); //random
}

TEST(MobTest, WolfLv1) {
  Wolf* wolf1 = new Wolf(1);
  EXPECT_EQ(wolf1->get_mob_hp(), 2);
  EXPECT_EQ(wolf1->get_mob_atk(), 4);
  EXPECT_EQ(wolf1->get_mob_def(), 2);
  EXPECT_NEAR(wolf1->get_mob_lvl(), 1, 3); //random
  EXPECT_NEAR(wolf1->get_mob_exp(), 20, 60); //random
  EXPECT_EQ(wolf1->getName(), "WOLF");
  EXPECT_NEAR(wolf1->attackChar(5), 2, 1); //random
}

TEST(MobTest, YetiLv1) {
  Yeti* yeti1 = new Yeti(1);
  EXPECT_EQ(yeti1->get_mob_hp(), 4);
  EXPECT_EQ(yeti1->get_mob_atk(), 2);
  EXPECT_EQ(yeti1->get_mob_def(), 2);
  EXPECT_NEAR(yeti1->get_mob_lvl(), 1, 3); //random
  EXPECT_NEAR(yeti1->get_mob_exp(), 10, 30); //random
  EXPECT_EQ(yeti1->getName(), "YETI");
  EXPECT_NEAR(yeti1->attackChar(5), 2, 1); //random
}

TEST(MobTest, DrakeLv5) {
  Drake* drake1 = new Drake(5);
  EXPECT_NEAR(drake1->get_mob_hp(), 15, 5); //random
  EXPECT_NEAR(drake1->get_mob_atk(), 15, 5); //random
  EXPECT_NEAR(drake1->get_mob_def(), 10, 5); //random
  EXPECT_NEAR(drake1->get_mob_lvl(), 5, 3); //random
  EXPECT_NEAR(drake1->get_mob_exp(), 15, 45); //random
  EXPECT_EQ(drake1->getName(), "DRAKE");
  EXPECT_NEAR(drake1->attackChar(5), 11, 7); //random
}

TEST(MobTest, TrollLv5) {
  Troll* troll1 = new Troll(5);
  EXPECT_NEAR(troll1->get_mob_hp(), 10, 5); //random
  EXPECT_NEAR(troll1->get_mob_atk(), 10, 5); //random
  EXPECT_NEAR(troll1->get_mob_def(), 20, 5); //random
  EXPECT_NEAR(troll1->get_mob_lvl(), 5, 3); //random
  EXPECT_NEAR(troll1->get_mob_exp(), 5, 15); //random
  EXPECT_EQ(troll1->getName(), "TROLL");
  EXPECT_NEAR(troll1->attackChar(5), 8, 6); //random
}

TEST(MobTest, WolfLv5) {
  Wolf* wolf1 = new Wolf(5);
  EXPECT_NEAR(wolf1->get_mob_hp(), 10, 5); //random
  EXPECT_NEAR(wolf1->get_mob_atk(), 20, 5); //random
  EXPECT_NEAR(wolf1->get_mob_def(), 10, 5); //random
  EXPECT_NEAR(wolf1->get_mob_lvl(), 5, 3); //random
  EXPECT_NEAR(wolf1->get_mob_exp(), 20, 60); //random
  EXPECT_EQ(wolf1->getName(), "WOLF");
  EXPECT_NEAR(wolf1->attackChar(5), 14, 9); //random
}

TEST(MobTest, YetiLv5) {
  Yeti* yeti1 = new Yeti(5);
  EXPECT_NEAR(yeti1->get_mob_hp(), 20, 5); //random 
  EXPECT_NEAR(yeti1->get_mob_atk(), 10, 5); //random
  EXPECT_NEAR(yeti1->get_mob_def(), 10, 5); //random
  EXPECT_NEAR(yeti1->get_mob_lvl(), 5, 3); //random
  EXPECT_NEAR(yeti1->get_mob_exp(), 50, 70); //random 
  EXPECT_EQ(yeti1->getName(), "YETI");
  EXPECT_NEAR(yeti1->attackChar(5), 8, 6); //random
}

#endif
