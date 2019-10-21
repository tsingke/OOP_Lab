/*************************************************
** 功能 : try-catch课堂演示  
** 作者 : tsingke
** 时间 : 2019-10-7 / 12:51
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;



double add(int a, int b)
{

	if (a+b == 0)
	{
		throw -1;
		cout << "-1"<< endl ;
		
		
	}
	return double(a + b);

}

double subtraction(int a, int b)
{
	if (a - b == 0)
	{
		throw - 2;
		cout << "-2" << endl;

	}

	return double(a - b);
}

double multiplication(int a, int b)
{
	if (a * b == 0)
	{
		throw - 3;
		cout << "-3" << endl;

	}

	return double(a * b);
}

double divide(int a, int b)
{

	if (b == 0)
	{
		throw - 4;

		cout << "-4"<< endl ;
		
	}

	return double(1.0*a / b);
}


double rootsum(int a,int b)
{

	if (a<0 && b<0)
	{
		throw -1.2;

		cout << "-5" << endl;

	}

	return double(sqrt(a)+sqrt(b));
}
/*----------------------------------*
          Main Function
*-----------------------------------*/



int main()
{

	cout << "try- catch 使用演示" << endl ;
	int a, b;

	do 
	{
		try
		{
			cout << endl<< "------输入两个数,输出他们的四则运算结果-----" << endl;

			cout << "a = "; cin >> a;

			cout << "b = "; cin >> b;


			cout << "a+b = " << add(a, b) << endl;


			cout << "a-b = " << subtraction(a, b) << endl;
			cout << "a*b = " << multiplication(a, b) << endl;
			cout << "a/b = " << divide(a, b) << endl;

			cout << "sqrt(a)+sqrt(b)= " << rootsum(a, b) << endl;


		}
		catch (const int e)
		{
			switch (e)
			{
			case -1: cout << "异常发生: a+b == 0"; break;
			case -2: cout << "异常发生: a-b == 0"; break;

			case -3: cout << "异常发生: a*b == 0"; break;

			case -4: cout << "异常发生: a/b == null"; break;

			default:
				break;
			}

		}
		catch (const double f)
		{
			cout << f << endl;
			cout << "异常发生: a<0 或b <0 " << endl;
		}

		
	} while (1);


	
	system("pause");
	
	return 0;
}