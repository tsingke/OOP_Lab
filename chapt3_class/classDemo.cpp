/*************************************************
** 功能 : 类的演示  
** 作者 : tsingke
** 时间 : 2019-10-15 / 08:58
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

//设计一个学生结构体

struct student_s
{
	string name;
	int id;
	int age;
	double high;
	double weight;
	double salary;

};



class date
{

public:
	int year;

private:
	
	int month;
	int day;

public:
	void display()
	{
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
	void initi(int y, int m, int d);

	void modifyear();

	int getmonth()
	{
		return month;
	}
};

void date::initi(int y,int m,int d)
{
	year = y;
	month = m;
	day = d;
}


/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{


	struct student_s wang;

	wang.name = "wanger";
	wang.id = 2018;
	wang.age = 20;
	wang.high = 1.75;
	wang.weight = 60;
	wang.salary = 7000;


	date today;


	today.initi(2019, 10, 15);

	today.display();


	today.year = 2020;

	cout<<today.getmonth()<<endl;
	

	system("pause");
	
	return 0;
}