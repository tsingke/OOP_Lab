#define _CRT_SECURE_NO_WARNINGS
#include "student.h"
#include<cstring>
#include<iostream>

using namespace  std;

// 使用构造函数完成对象的初始化
student::student()
{

}

student::student(char *na, int age, int gender)
{

    cout << "+构造函数被调用" << endl;
    if (na != NULL)
    {
        int len = strlen(na);

        this->name = new char[len + 1];

        strcpy(this->name, na);
    }

    this->age = age;

    this->gender = gender;

}

student::student(const student &r)
{
    cout << "+拷贝构造函数被调用" << endl;

    //系统默认对位拷贝
    //this->name = r.name;//浅拷贝,仅涉及栈上的数据对位拷贝,不涉及堆

    if (r.name!=NULL)//深度拷贝--仅仅针对有堆数据拷贝的情况
    {

        this->name = new char[strlen(r.name) + 1];

        strcpy(name, r.name);
    }


    this->age = r.age;
    this->gender = r.gender;

}

student::~student()
{
    //删除堆空间
    if (this->name != NULL)
    {
        delete[] name;
    }

    cout << "~析构函数被调用" << endl;


}

void student::display()
{
    cout << "name  = " << name << endl;
    cout << "age   = " << age << endl;
    cout << "gender= " << this->gender << endl;

}
