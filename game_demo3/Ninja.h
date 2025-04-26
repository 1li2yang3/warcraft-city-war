#ifndef GAME_DEMO_NINJA_H
#define GAME_DEMO_NINJA_H
#include "Warrior.h"
class Ninja:public Warrior{
private:
    int WeaponType1;
    int WeaponType2;

public:
    Ninja(int Dlife,int atk);
    void setWeaponType1(int type);
    void setWeaponType2(int type);
    int getWeaponType1();
    int getWeaponType2();
    int getTypeName();
    string getType();
};
#endif //GAME_DEMO_NINJA_H
