/*************************************************
** 功能 : 类的继承中,父子类间同名冲突问题(单继承)  
** 作者 : tsingke
** 时间 : 2019-11-25 
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;


class base
{
private:
	int a;
public:
	base(int _a):a(_a) 
	{
		this->a = _a;;
	}
	~base() {}
	int get() { return a; }

};

class derived : public base
{
private:
	int a;
public:
	derived(int _a) :base(_a*10)
	{
		this->a = _a;
	}

	~derived() {}

	int get() { return a; }

};

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{

	base b(10);
	derived d(20);


	//1.冲突解决: 通过域名解析符来访问被子类遮挡的父类的同名成员
	cout<<"d.get()= "<< d.get()<<endl;     //访问派生类的get函数(掩盖了基类的get函数)

	cout<<"d.base::get()= "<<d.base::get()<<endl;//访问父类中的同名函数,通过域名解析的方法

	//2.基类指针用法

	cout << "------基类指针指向派生类对象----------" << endl;
	base *pb;
	pb = &d;
	cout<<"pb->get() = "<<pb->get()<<endl;//通过基类指针指向派生类对象, 基类指针仅能访问到被派生类继承过去的成员数据或成员函数
	
	//3. 基类引用用法
	cout << "------基类引用,引用派生类对象----------" << endl;

	base &r = d;
	cout <<" r.get() = "<< r.get() << endl;//


	system("pause");
	
	return 0;
}