/*************************************************
** 功能 : 类的演示
** 作者 : tsingke
** 时间 : 2019-10-15 / 15:12
***************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <windows.h>

using namespace std;





class triangle
{

private:
	double a;
	double b;
	double c;

public:


	void inti(int, int, int);

	bool isTriangle();

	double perimeter();

	double area();

	int typeTriangle();

	void ModifyA(int);


};

bool triangle::isTriangle()
{

	if ((a + b) > c && (a + c) > b && (b + c) > a)
	{
		return true;
	}

	else
		return false;
}

void triangle::inti(int s1, int s2, int s3)
{

	a = s1;
	b = s2;
	c = s3;

	if (isTriangle() == false)
	{
		cout << "无法构成三角形,退出程序!" << endl;

		exit(0);
	}

}

double triangle::perimeter()
{

	return a + b + c;

}


double triangle::area()
{

	double  p = perimeter() / 2.0;

	return sqrt(p*(p - a)*(p - b)*(p - c));

}

int triangle::typeTriangle()
{

	if (pow(a, 2) + pow(b, 2) == pow(c, 2))
	{
		return 1;
	}
	else if (pow(a, 2) + pow(b, 2) < pow(c, 2))
	{
		return 2;
	}
	else
	{
		return 3;
	}




}

void triangle::ModifyA(int s)
{
	a = s;//间接修改边长a的数值
}


/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{
	triangle t;

	int ta, tb, tc;


	//t.a = 666;//无法直接访问私有数据

	t.ModifyA(6666);

	cout << "pleaes input three edges: " << endl;

	cin >> ta;
	cin >> tb;
	cin >> tc;

	t.inti(ta, tb, tc);


	cout << "周长=" << t.perimeter() << endl;
	cout << "面积= " << t.area() << endl;

	if (t.typeTriangle() == 1)
	{
		cout << "直角三角形" << endl;

	}
	else if (t.typeTriangle() == 2)
	{
		cout << "锐角三角形" << endl;

	}
	else
		cout << "钝角三角形" << endl;



	system("pause");

	return 0;
}