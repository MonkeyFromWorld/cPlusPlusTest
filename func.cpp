//
// Created by cxj on 2019/10/21.
//

#include "func.h"
#include <utility>
using namespace std;

Person::Person(string initName, uint initAge) {
    this->name = std::move(initName);
    this->age = initAge;
    //��
    //name = ...
    //age = ...
}

void Person::setAge(uint newAge) {
    this->age = newAge;
    //��
    //age = ...
}

void Person::setName(string newName) {
    this->name = std::move(newName);
    //��
    //name = ...
}

string Person::getName() {
    return this->name;
    //��
    //return name

}

uint Person::getAge() {
    return this->age;
    //��
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
    cout << "father������" << endl;
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
    cout << "child������" << endl;
}

void Child::showName() {
    Parent::showName();//��������Ĵ��뼴����Ϊ�ڷ��ຯ���ϵĲ��䣬û���������Ϊ�ǶԸ��ຯ������д��
    cout << this->name << "���/��д!" << endl;
}
