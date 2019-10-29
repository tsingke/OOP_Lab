#include "student.h"
#include <iostream>

using namespace std;


student::student(int id, const char *user_name)
{
	cout << "构造函数被调用" << endl;
	this->id = id;

	if (user_name!=NULL)
	{
		int len = strlen(user_name);

		name = new char[len + 1];

		strcpy(name, user_name);

	}



}

student::student(const student & r)
{
	this->id = r.id;

   // this->name = r.name;//浅拷贝<-----栈上操作

	if (r.name!=NULL)//深度拷贝<---堆上操作
	{
		int len = strlen(r.name);

		this->name = new char[len + 1];

		strcpy(this->name, r.name);
	}
}


student::~student()
{
	cout << "--析构函数被调用--" << endl;

	delete[] name;
}

void student::display()
{
	cout << "学号id  = " << id << endl;

	cout << "姓名name= " << name << endl;


}
