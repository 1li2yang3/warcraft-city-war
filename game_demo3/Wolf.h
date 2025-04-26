#ifndef GAME_DEMO_WOLF_H
#define GAME_DEMO_WOLF_H
#include "Warrior.h"
class Wolf:public Warrior{
private:

public:
    Wolf(int Dlife,int atk);
    int getTypeName();
    string getType();
};
#endif //GAME_DEMO_WOLF_H
