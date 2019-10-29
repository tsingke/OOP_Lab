#pragma once
class student
{

private:
	int id;
	char *name; //申请动态内存的信号

public:
	//1. 构造函数，析构函数

	student(int id, const char *user_name);

	student(const student &r);

	~student();


	//2. 普通函数
	void display();
};

