#ifndef GAME_DEMO_DRAGON_H
#define GAME_DEMO_DRAGON_H
#include "Warrior.h"
class Dragon:public Warrior{
private:
    int WeaponType;
    double Morale;
public:
    Dragon(int Dlife,int atk);
    void setWeaponType(int type);
    void setMorale(double morale);
    int getWeaponType();
    double getMorale();
    int getTypeName();
    string getType();
};
#endif //GAME_DEMO_DRAGON_H
