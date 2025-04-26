#include <iomanip>
#include "game.h"
int nextR(int r){
    if(r==3){
        return 4;
    }else if(r==4){
        return 5;
    }else if(r==5){
        return 2;
    }else if(r==2){
        return 1;
    }else{
        return 3;
    }
}
int nextB(int b){
    if(b==4){
        return 1;
    }else if(b==1){
        return 2;
    }else if(b==2){
        return 3;
    }else if(b==3){
        return 5;
    }else{
        return 4;
    }
}
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int m,n,k,end; //m为生命元，n为城市个数，k为减少的忠诚度
        int now,isEnd=0;
        cin>>m>>n>>k>>end;
        Headquarter red(m,"red"),blue(m,"blue");
        int life[5];
        for(int & j : life){
            cin>>j;
        }
        int atk[5];
        for(int & j : atk){
            cin>>j;
        }
        int hour=0;
        int minutes=0;
        cout<<"Case "<<i+1<<":"<<endl;
        int r=3,b=4;
        //vector<Warrior*> arr;
        bool RedContinue=true;
        bool BlueContinue=true;
        while(true){
            //士兵生成
            //红方生成士兵
            if(red.getTotalLife()>=life[r-1] && RedContinue){
                cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                red.createWarrior(r,life[r-1],atk[r-1]);
                r= nextR(r);
            }else{
                RedContinue=false;
            }
            //蓝方生成士兵
            if(blue.getTotalLife()>=life[b-1] && BlueContinue){
                cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
                blue.createWarrior(b,life[b-1],atk[b-1]);
                b= nextB(b);
            }else if(BlueContinue){
                BlueContinue=false;
            }
            //士兵生成结束
            minutes+=5;
            now=hour*60+minutes;
            if(end<now)
                break;
            //lion逃跑
            /*
            red.checkLion(hour,minutes);
            blue.checkLion(hour,minutes);
             */
            red.checkLion(hour,minutes,blue,n);
            //逃跑结束
            minutes+=5;
            now=hour*60+minutes;
            if(end<=now)
                break;
            //武士前进
            red.goNextCity(n,k);
            blue.goNextCity(n,k);
            red.reportCity(hour,minutes,blue,n,&isEnd);
            if(isEnd==1){
                //cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes<<" blue headquarter was taken"<<endl;
                break;
            }else if(isEnd==-1){
                //cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes<<" red headquarter was taken"<<endl;
                break;
            }else if(isEnd==2){
                //cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes<<" red headquarter was taken"<<endl;
                //cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes<<" blue headquarter was taken"<<endl;
                break;
            }
            //前进完成
            minutes+=25;
            now=hour*60+minutes;
            if(end<now)
                break;
            //wolf抢夺武器
            /*
            red.fightForWeapon(hour,minutes,blue);
            blue.fightForWeapon(hour,minutes,red);
             */
            red.fightForWeapon(hour,minutes,blue,n);
            //抢夺完成
            minutes+=5;
            now=hour*60+minutes;
            if(end<now)
                break;
            //赛前整理武器
            red.adjustWeapon();
            blue.adjustWeapon();
            //开战
            red.fight(blue);
            //汇报战斗情况
            red.reportAlive(hour,minutes,blue,n);
            //收集武器
            red.getWeapon(blue);
            blue.getWeapon(red);
            //欢呼
            /*
            red.warriorYell(hour,minutes);
            blue.warriorYell(hour,minutes);
             */
            //red.warriorYell(hour,minutes,blue,n);
            //士兵清除
            red.clearDied();
            blue.clearDied();
            //结束
            minutes+=10;
            now=hour*60+minutes;
            if(end<now)
                break;
            //司令部报告生命元数量
            cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
            cout<<" "<<red.getTotalLife()<<" elements in "<<red.getName()<<" headquarter"<<endl;
            cout<<setw(3)<<setfill('0')<<hour<<":"<<setw(2)<<setfill('0')<<minutes;
            cout<<" "<<blue.getTotalLife()<<" elements in "<<blue.getName()<<" headquarter"<<endl;
            //结束
            minutes+=5;
            now=hour*60+minutes;
            if(end<now)
                break;
            //武士报告武器情况
            /*
            red.reportWeapon(hour,minutes);
            blue.reportWeapon(hour,minutes);
             */
            red.reportWeapon(hour,minutes,blue,n);
            //分钟重置，小时+1
            minutes=0;
            hour++;
            now=hour*60+minutes;
            if(end<now)
                break;
        }
    }
    return 0;
}
