#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "Character.h"


class Knight : public Character {

    public:
       Knight(string, characterType);
       void attack();
       void levelUp();

};


#endif //__KNIGHT_H__
