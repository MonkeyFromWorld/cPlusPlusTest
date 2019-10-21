//
// Created by cxj on 2019/10/21.
//

#include "func.h"
#include <utility>
using namespace std;

Person::Person(string initName, uint initAge) {
    this->name = std::move(initName);
    this->age = initAge;
    //或：
    //name = ...
    //age = ...
}

void Person::setAge(uint newAge) {
    this->age = newAge;
    //或：
    //age = ...
}

void Person::setName(string newName) {
    this->name = std::move(newName);
    //或：
    //name = ...
}

string Person::getName() {
    return this->name;
    //或：
    //return name

}

uint Person::getAge() {
    return this->age;
    //或：
    //return age
}

Person& Person::operator=(const Person& right) {
    delete[](&name);
    name = new char [right.name.length()+1];
    name = right.name;
    age = right.age;
    return *this;
}

Parent::Parent(string name, uint age, uint ID) {
    this->name = name;
    this->age = age;
    this->ID = ID;
}

Parent::~Parent() {
    cout << "father析构。" << endl;
}

void Parent::showName() {
    cout << this->name << endl;
}

Child::Child(string name, uint age, uint id) : Parent(name, age, id) {
    this->name = name;
    this->ID = ID;
}

void Child::showNameAgain() {
    cout << this->name << endl;
    cout << this->name << endl;
}

Child::~Child() {
    cout << "child析构。" << endl;
}

void Child::showName() {
    Parent::showName();//有这句后面的代码即可认为在夫类函数上的补充，没有这句则认为是对父类函数的重写。
    cout << this->name << "添加/重写!" << endl;
}
