#ifndef PET_H
#define PET_H
//pet类包含宠物的信息
//直接移植


#include<QString>
#include<define.h>

class Pet
{
public:
    Pet();
    void setName(QString name);//设置函数
    void setState(QString state);
    void setWeight(double weight);
    void setAge(int age);
    void setMood(int mood);
    void setHealth(int health);
    void setHunger(int hunger);
    void setActive(int active);
    void setWidth(int width);
    void setHeight(int height);

    QString getName();//返回函数
    QString getState();
    double getWeight();
    int getAge();
    int getMood();
    int getHealth();
    int getHunger();
    int getActive();
    int getWidth();
    int getHeight();


private:
    QString name="echo_gn";  //昵称
    QString state="healthy";   //状态
    double  weight=WEIGHT;      //体重
    int  age=AGE;          //年龄
    int  mood=MOOD;       //心情
    int health=HEALTH;      //健康
    int hunger=HUNGER;    //饥饿度
    int active=ACTIVE;      //活力值
    int width=WIDTH;      //宠物宽度
    int height=HEIGHT;    //宠物高度
};

#endif // PET_H
