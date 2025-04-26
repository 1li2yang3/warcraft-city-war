#ifndef GAME_DEMO_WARRIOR_H
#define GAME_DEMO_WARRIOR_H
#include "Object.h"
#include <vector>
#include <string>
using namespace std;
class Warrior: public Object{
private:
    int HP;
    int ATK;
    vector<int> Weapon;
    vector<int> remain;
    int AtCity;
    //int type;
public:
    Warrior();
    virtual ~Warrior();
    int getHP();
    int getATK();
    void setHP(int hp);
    void setATK(int atk);
    void addWeapon(int type,int remain);
    virtual int getTypeName()=0;
    virtual string getType()=0;
    void nextCity();
    void beforeCity();
    void setAtCity(int AtCity);
    int getAtCity();
    int minWeapon();
    int firstWeapon();
    int firstRemain();
    int lastWeapon();
    int lastRemain();
    int deleteWeapon(int type);
    int deleteAWeapon(int type);
    int numberOfThisWeapon(int type);
    int weaponNumber();
    int newArrow();
    int oldArrow();
    int deleteArrow();
    void deleteNewArrow();
    void deleteOldArrow();
    int numberOfSword();
    int numberOfBomb();
    int numberOfArrow();
    void adjustWeapon();
    int fight(int *n,int *number,int atk,int *same);
    //void setType(int t);
    //int getType();
};
#endif //GAME_DEMO_WARRIOR_H
