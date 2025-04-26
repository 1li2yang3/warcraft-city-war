#ifndef GAME_DEMO_LION_H
#define GAME_DEMO_LION_H
#include "Warrior.h"
class Lion:public Warrior{
private:
    int Loyalty;
    int WeaponType;
public:
    Lion(int Dlife,int atk);
    void setWeaponType(int type);
    int getWeaponType();
    void setLoyalty(int loyalty);
    int getLoyalty();
    int getTypeName();
    string getType();
};
#endif //GAME_DEMO_LION_H
