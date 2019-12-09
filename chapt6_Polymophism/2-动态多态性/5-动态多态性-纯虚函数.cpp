/*************************************************
** 功能 : 纯虚函数与抽象类  
** 作者 : 张庆科
** 时间 : 2019-12-9
***************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>    //不要落掉,调用其sqrt()函数
#include <windows.h>

using namespace std;


//----------------抽象类: 图形类-------------------

class shape
{
public:
	virtual double circumstance() = 0;

	virtual double area() = 0; //含有纯虚函数的类就是抽象类

};

//----------------具体类:正方形类-------------------

class squre:public shape
{
private:
	double a;

public:
	squre(int _a) :a(_a)
	{
		cout << "生成正方形对象, 边长 = " << a << endl;
	}
	~squre() {}

	double circumstance()//基类同名为虚函数,子类相同函数自动变为虚函数(公有继承,长相相同)
	{
		return 4 * a;
	}

	double area()       //基类同名为虚函数,子类相同函数自动变为虚函数(公有继承,长相相同)
	{
		return a * a;
	}

};

//----------------具体类:三角形类-------------------

class triangle:public shape
{
private:
	double a, b, c;
public:
	triangle(double _a, double _b, double _c) :a(_a), b(_b), c(_c) 
	{

		if ((a+b<=c) || (a+c<=b) || (b+c <=a))
		{
			cout << "无法构成三角形,请重新输入三条边:" << endl;
			cin >> a;
			cin >> b;
			cin >> c;
		}

		cout << "生成三角形对象, 边长 = " << a <<" "<< b << " " << c<<endl;



	}
	~triangle() {}

	double circumstance() //基类同名为虚函数,子类相同函数自动变为虚函数(公有继承,长相相同)
	{
		return a + b + c;
	}

	double area()        //基类同名为虚函数,子类相同函数自动变为虚函数(公有继承,长相相同)
	{
		double p = 0.5 * circumstance();

		return sqrt(p*(p - a)*(p - b)*(p - c));

	}

};

//全局函数,输出某个图形的周长和面积
void display(shape *p)
{


	cout << "周长为: " << p->circumstance() << endl;//多态语句(指哪打哪)
	cout << "面积为: " << p->area() << endl;        //多态语句(指哪打哪)

	cout << "------------------------------" << endl;
}



/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{

	squre squ(10);         //正方形类对象

	triangle tri(3, 4, 5); //三角形类对象


	//------------1. 抽象类的特性探索----------

	//shape sha;  // 错误, 不可以生成抽象类的对象
	cout << "sizeof(shape) = " << sizeof(shape) << endl;//可以计算抽象类大小

	shape *p;     // 正确, 可以建立抽象类的指针变量
	shape &r = squ;//正确, 可以建立抽象类的对象引用,引用的是派生类对象


	//-----------2. 动态多态特性探索-----------
	cout << endl;

	cout << "正方形的周长和面积:"<<endl;
	display(&squ);//输出正方形的周长和面积, 指哪打哪

	cout << "三角形周长和面积:"<<endl;
	display(&tri);//输出三角形的周长和面积, 指哪打哪

	


	system("pause");
	
	return 0;
}