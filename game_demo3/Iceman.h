#ifndef GAME_DEMO_ICEMAN_H
#define GAME_DEMO_ICEMAN_H
#include "Warrior.h"
class Iceman:public Warrior{
private:
    int WeaponType;
public:
    Iceman(int Dlife,int atk);
    void setWeaponType(int type);
    int getWeaponType();
    int getTypeName();
    string getType();
};
#endif //GAME_DEMO_ICEMAN_H
