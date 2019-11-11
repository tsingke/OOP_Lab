/*************************************************
** 功能 : 常数据成员,常成员函数,常对象  
** 作者 : tsingke
** 时间 : 2019-11-12 / 00:03
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

class circle
{

private:

	double R;
	const double pi;//常成员变量
	static int TotalCount;
public:

	circle(double r = 0):pi(3.1415926)
	{
		this->R = r;
		
	}


	//修改半径
	double getR()     //普通函数
	{
		cout << "getR()被调用" << endl;
		return R;
	}

	//访问半径
	double getR() const  //常成员函数,重装函数
	{
		cout << "getR()const被调用" << endl;

		//setR(2);//报错,因为常函数不能访问普通非常函数,只能常对常访问
		return R;
	}

	//访问半径
	void setR(double r)
	{
		R = r;
	}

	//输出面积
	double area()
	{
		getR();//普通函数可以访问常函数
		return pi * R*R;
	}

	//输出周长
	double circumstance()
	{
		return 2 * pi*R;
	}

};

int circle::TotalCount = 0;//定义初始化静态成员变量


/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{


	circle A;//普通的对象
	const circle B(3.5);//常对象,带参初始化(务必要初始化)
	const circle C;//常对象,采用构函默认值初始化

	cout<< "A.getR() = "<< A.getR()<<endl;//普通对象调用对应的非常函数,如果非常函数不存在,就调用常函数
	cout<< "B.getR() = " <<B.getR()<<endl;//常对象调用常函数

	
	A.setR(5.4);//正确,普通对象可访问所有类内普通函数
	//B.setR(12);//报错,常对象不能访问普通函数,必须访问常成员函数



	system("pause");
	
	return 0;
}