#ifndef GAME_DEMO2_HEADQUARTER_H
#define GAME_DEMO2_HEADQUARTER_H
#include "Object.h"
#include <string>
#include <iostream>
#include <vector>
#include "Dragon.h"
#include "Ninja.h"
#include "Iceman.h"
#include "Lion.h"
#include "Wolf.h"
#include "Warrior.h"
#include <iomanip>
using namespace std;
class Headquarter{//指挥部类
private:
    string name; //指挥部的名字
    int totalLife; //指挥部当前生命元
    int numberOfDragon; //Dragon数量
    int numberOfWarrior; //士兵的数量/编号
    int numberOfNinja; //Ninja的数量
    int numberOfIceman; //Iceman数量
    int numberOfLion; //Lion数量
    int numberOfWolf; //Wolf数量
    vector<Warrior*> warrior; //存放所有士兵的地址
    vector<Lion*> lion; //存放Lion的地址
    vector<Iceman*> iceman; //存放Iceman的地址
    vector<Wolf*> wolf; //存放Wolf的地址
    vector<Dragon*> dragon; //存放Dragon的地址
    string getWeaponName(int n); //返回根据武器的数字编号返回武器的名称
public:
    Headquarter(int totalLife=0,string str=NULL); //指挥部的构造函数
    ~Headquarter(); //指挥部的析构函数
    int getTotalLife(); //返回当前生命元
    void decreaseTotalLife(int Dlife); //减少指挥部的生命元
    void increaseWarrior(); //增加士兵数量
    void increaseDragon(); //增加Dragon数量
    void increaseNinja(); //增加Ninja数量
    void increaseIceman(); //增加Iceman数量
    void increaseLion(); //增加Lion数量
    void increaseWolf(); //增加Wolf数量
    int getNumberOfDragon(); //获取Dragon的数量
    int getNumberOfNinja(); //获取Ninja的数量
    int getNumberOfIceman(); //获取Iceman的数量
    int getNumberOfLion(); //获取Lion的数量
    int getNumberOfWolf(); //获取Wolf的数量
    int getNumberOfWarrior(); //获取士兵的数量/编号（士兵消失不会减少），士兵的真实数量由士兵的vector的大小确定
    string getName(); //获得当前指挥部的名称red/blue
    void createWarrior(int type,int hp,int atk); //创建士兵
    void checkLion(int hour,int minutes,Headquarter &headquarter,int n); //检查狮子是否逃跑
    void goNextCity(int n,int k); //前往下一个城市
    void reportCity(int hour,int minutes,Headquarter &headquarter,int n,int* isEnd); //报告所在城市
    void fightForWeapon(int hour,int minutes,Headquarter &headquarter,int n); //Wolf抢夺武器
    void reportWeapon(int hour,int minutes,Headquarter &headquarter,int n); //报告武器
    void warriorYell(int hour,int minutes,Headquarter &headquarter,int n); //士兵yell
    void adjustWeapon(); //战斗前调整武器
    void fight(Headquarter &headquarter); //战斗
    void reportAlive(int hour,int minutes,Headquarter &headquarter,int n); //报告士兵是否存活
    void getWeapon(Headquarter &headquarter); //士兵拾取武器
    void clearDied(); //清除死亡士兵
};
#endif //GAME_DEMO_HEADQUARTER_H
