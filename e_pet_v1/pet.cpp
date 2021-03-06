#include "pet.h"
//pet类的具体函数内容
//直接移植
Pet::Pet()
{
    name="echo_gn";
    state="healthy";
    weight=WEIGHT;
    age=AGE;
    mood= MOOD;
    health=HEALTH;
    hunger=HUNGER;
    active=ACTIVE;
    width=WIDTH;
    height=HEIGHT;
}

void Pet::setName(QString name){
    this->name=name;
}

void Pet::setState(QString state){
     this->state=state;
}

void Pet::setWeight(double weight){
    this->weight=weight;
}

void Pet::setAge(int age){
    this->age=age;
}

void Pet::setMood(int mood){
    this->mood=mood;
}

void Pet::setHealth(int health){
    this->health=health;
}

void Pet::setHunger(int hunger){
    this->hunger=hunger;
}

void Pet::setActive(int active){
    this->active=active;
}

void Pet::setWidth(int width){
    this->width=width;
}

void Pet::setHeight(int height){
    this->height=height;
}

QString Pet::getName(){
    return name;
}

QString Pet::getState(){
    return state;
}

double Pet::getWeight(){
    return weight;
}

int Pet::getAge(){
    return age;
}

int Pet::getMood(){
    return mood;
}

int Pet::getHealth(){
    return health;
}

int Pet::getHunger(){
    return hunger;
}

int Pet::getActive(){
    return active;
}

int Pet::getWidth(){
    return width;
}

int Pet::getHeight(){
    return height;
}
