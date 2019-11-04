/*************************************************
** 功能 : 对象的使用
** 作者 : tsingke
** 时间 : 2019-11-4 / 18:02
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;


class date
{
	//1.类的变量记心间
private:
	int year;
	int month;
	int day;

public:

	//2. 三构一析放在前
	date();
	date(int year, int month, int day);
	date(const date &r);
	~date();


	//3.普函定义按需添

	int getYear();
	int getMonth();
	int getDay();

	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);



	void display();


};

//---------------类成员函数的实现----------------------
date::date()
{
	cout << "++无参构造函数被调用++" << endl;
	year = 2019;
	month = 01;
	day = 01;
}

date::date(int year, int month, int day)
{
	cout << "++有参构造函数被调用++" << endl;

	this->year = year;
	this->month = month;
	this->day = day;
}

date::date(const date & r)
{
	this->year = r.year;
	this->month = r.month;
	this->day = r.day;
}

date::~date()
{
	cout << "--析构函数被调用--" << endl;
}

int date::getYear()
{
	return year;
}

int date::getMonth()
{
	return month;
}

int date::getDay()
{
	return day;
}

void date::setYear(int y)
{
	this->year = y;
}

void date::setMonth(int m)
{
	this->month = m;
}

void date::setDay(int d)
{
	this->day = d;

}

void date::display()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}


//==================全局函数=========================


void print(date &r)
{
	cout << r.getYear() << "年" << r.getMonth() << "月" << r.getDay() << "日" << endl;
}


//对象作为参数(对象,对象指针,对象引用)
void objectAsArgument(date t, date * p, date & r)
{
	//传值形式无法修改原对象内容,但可以访问到原对象内相同的数据
	t.setYear(2050);
	t.setMonth(10);
	t.setDay(24);


	//通过指针修改原对象内容
	p->setYear(2035);
	p->setMonth(6);
	p->setDay(1);


	//通过引用修改原对象内容
	r.setYear(2050);
	r.setMonth(10);
	r.setDay(24);

}

/*----------------------------------*
		  Main Function
*-----------------------------------*/


//使用方法: 把#if 后面的0改成1即可调试对应区域代码

int main()
{


	
#if 0
	//----------------------第一块演示: 对象的数组----------------------------------

	//a1.栈对象数组的定义

	//date array_1[3];//调用无参构造函数
	//date array_2[3] = { date(2019,10,1),date(2019,10,2) };//按需调用构造函数

	//a2.堆对象数组的定义
	//date *parray_1 = new date[3];//调用无参构造函数

	date *parray_2 = new date[3];//调用无参构造函数

	date *temp = parray_2;

	parray_2[0] = date(2020, 1, 1);
	parray_2[1] = date(2020, 1, 2);
	parray_2[2] = date(2020, 1, 3);



	//b. 对象数组元素访问对象成员的方式(2种)

	for (int i = 0; i < 3; i++)
	{
		
		//array_1[i].display();//直接访问对象成员法


		//array_2[i].display();//直接访问对象成员法


		//(parray_1++)->display();//间接访问对象成员法

		(parray_2++)->display();//间接访问对象成员法
		//循环体执行完本语句后,如果在程序里用delete[]parray_2就会报错,因为
		//此时parray_2不再指向动态数组的首地址,而是第3个元素的地址,所以
		//建议使用直接访问的方式比较稳妥!!!!

		

		
	}

	delete[]temp;

#endif

#if 0
	//---------------------第二块演示:对象的指针----------------------------------

	date s1;

	//1. 探索指针的初始化,建议定义指针变量时务必对其进行初始化,否则后患无穷!!
	date *p = NULL;//如果这里令 date *p=1,就会报错,这里的NULL实际是0,本质上是个地址,即NULL=0=00000000
	cout << "p指向到哪里:" << p << endl;

	p = 0;//这里的0,本质上是个地址,即0=00000000,如果改成p=1,报错,因为1不是内存地址.
	cout << "p指向到哪里:" << p << endl;


	//2.指针的两种用法
	p = &s1;

	s1.getYear();


	(*p).getYear();
	p->getYear();

#endif


#if 0
	//----------------------第三块演示:对象的引用----------------------------------

	date today;

	date &r = today;

	today.display();
	r.display();


	date tomorrow(2030, 10, 1);


	//r自始至终都是today的引用,不会变化
	//通过改变today或r的值,彼此内容都会发生变化
	r = tomorrow;

	today.display();



	//对象引用的核心作用:作为函数的形参
	
	print(today);

#endif

#if 0

	//----------------------第四块演示:.对象作为参数(对象,对象指针,对象引用)----------------------------------

	date day_1(1970, 1, 1);
	date day_2(1970, 1, 1);
	date day_3(1970, 1, 1);
	

	objectAsArgument(day_1, &day_2, day_3);

	day_1.display();//day_1对象没有被修改(数值)
	day_2.display();//day_2对象已经被修改(指针)
	day_3.display();//day_3对象已经被修改(引用)

#endif

	//-----------------------------------Over---------------------------------------------------------------

	system("pause");//如果想查看析构函数被调用情况,请单步调试,一直F10即可.

	return 0;
}


