/*************************************************
** 功能 : 类的多继承-同名冲突问题/基类构函调用次序问题 
** 作者 : tsingke
** 时间 : 2019-11-25 
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

class base2
{
public:
	int a;
	base2(int _a)
	{
		cout << "base2() is called" << endl;
		this->a = _a;
	}
	~base2()
	{
		cout << "~base2() is called" << endl;
		getchar();

	}
	void print()
	{
		cout << "base2的a = " << a << endl;
	}

};

class base1
{
public:
	int a;
	base1(int _a)
	{
		cout << "base1() is called" << endl;
		this->a = _a;
	}
	~base1()
	{
		cout << "~base1() is called" << endl;
		getchar();

	}
	void print()
	{
		cout << "base1的a = " << a << endl;
	}
};




//构造函数调用次序与下面"定义派生类"时各个基类出现的先后顺序有关,与其在文件中定义的顺序无关
class derived : public base2, public base1
{
public:
	int a;
public:
	derived(int _a):base1(_a * 2),base2(_a * 3)

	{
		cout << "derived() is called" << endl;

		this->a = _a;
	}
	~derived()
	{
		cout << "~derived() is called" << endl;
		getchar();

	}
	void print()
	{
		cout << "derived的a = " << a << endl;
	}
};

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{


	//1. 派生类访问自己的数据

	derived d(1);

	cout << "d.a = " << d.a << endl;

	d.print();//优先访问派生类的函数

	cout << "-----------------------" << endl;

	//2.派生类对象访问父类继承的数据成员

	cout << "d.base1::a = " << d.base1::a << endl;
	cout << "d.base2::a = " << d.base1::a << endl;


	cout << "-----------------------" << endl;

	//3. 访问基类中的同名函数

	d.base1::print();//访问基类1中的同名函数

	d.base2::print();//访问基类2中的同名函数





	system("pause");
	
	return 0;
}