/*************************************************
** 功能 : 构造函数的使用  
** 作者 : tsingke
** 创建 : 2020-11-2 
** 版权 : tsingke@sdnu.edu.cn
/**************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Date
{

private: 
	int year, month, day;

public:
	Date()
	{
		cout << "无参构造函数被调用!" << endl;
	}

	Date(int year, int month, int day)
	{

		this->year = year;
		this->month = month;
		(*this).day = day;
		cout << "普通构造函数被调用!" << endl;
	}

	Date(const Date& r)
	{
		this->year = r.year;
		this->month = r.month;
		this->day = r.day;
		cout << "拷贝构造函数被调用!" << endl;
	}

	~Date()
	{
		cout << "~析构函数被调用(回车继续)!" << endl;
		getchar();
	}


};


//全局函数,返回类的对象类型
Date func(Date val)
{

	cout << "func()is called" << endl;

	return val;//调用拷贝构函,情形三
}


/*----------------------------------*
*         Main Function
*-----------------------------------*/

int main()
{

	Date lastday;//调用无参构函

	Date today(2020, 11, 1);//调用有参构函

	Date tommory(today);//调用拷贝构函(情形一)

	func(tommory);//调用拷贝构函(情形二)
	
	today = Date(2021,11,11);//调用普通有参构函,不会调用拷贝构函


	system("pause");
	
	return 0;
}

