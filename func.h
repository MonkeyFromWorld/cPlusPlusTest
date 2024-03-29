//
// Created by cxj on 2019/10/21.
//

#ifndef CPLUSPLUSTEST_FUNC_H
#define CPLUSPLUSTEST_FUNC_H

#include <string>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned int uint;

class Person {
private:
    string name;
    uint age;
public:
    explicit Person(string name="", uint age=0);
    void setAge(uint age);
    void setName(string name);
    string getName();
    uint getAge();
    Person& operator=(const Person& right);
};

class Parent {
public:
    string name;
    Parent(string name="father", uint age=1, uint ID=1);
    virtual ~Parent();//当一个成员函数要被子类重写时，那么父类应该将其申明为virtual,如果父类函数被定义为vitural时将调用子类的
    void showName();
private:
    uint age;
protected:
    uint ID;
};

class Child:public Parent {
public:
    Child(string name="child", uint age=0, uint id=0);
    ~Child();
    void showName();
    void showNameAgain();
};

class Msg {
public:
    virtual void Display() {
        cout << "Msg" << endl;
    }
};

class Tea: public Msg {
public:
    virtual void Display() {
        cout << "Tea" << endl;
    }
};

class Stu : public Msg {
public:
    virtual void Display() {
        cout << "Stu" << endl;
    }
};

void showMsg(Msg &c);

class CStudent
{
public:
    char Name[20];  //假设学生姓名不超过19个字符，以 '\0' 结尾
    char Id[10];  //假设学号为9位，以 '\0' 结尾
    int age;  //年龄
};
#endif //CPLUSPLUSTEST_FUNC_H
