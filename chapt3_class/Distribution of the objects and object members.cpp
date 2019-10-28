/*************************************************
** 功能 : 对象的访问  
** 作者 : tsingke
** 时间 : 2019-10-21 / 22:27
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;



class date
{


private:

	int year;
	int month;
	int day;

public:
	void setDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;

	}
	void display()
	{

		cout << "year=" << year << " month= " << month << " day=" << day << endl;
	}

	void address()
	{

		cout << "year的地址:" << &this->year << endl;
		cout << "month的地址:" <<& this->month << endl;
		cout << "day的地址:" << & this->day<< endl;


	}


};

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{

	
	date a;
	date *p =&a;
	
	//1.对象直接访问其内容
	a.setDate(2019, 10, 22);
	a.display();



	(*p).display();


	//2. 指针间接访问对象内容
	p->display();




	//3. 探索类对象内数据成员的存放规律

	date b;
	date c;

	b.setDate(2019, 12, 31);
	c.setDate(2020, 12, 31);

	cout << endl;

	//3.分析对象的分布规律(高地址-低地址)
	cout << "对象b的地址" << &b << endl;
	cout << "对象c的地址" << &c << endl;

	cout << endl;

	//4.分析对象内变量的分布规律(低地址--高地址)
	b.address();
	//c.address();

	system("pause");
	
	return 0;
}
