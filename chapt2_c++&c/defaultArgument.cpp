/*************************************************
** 功能 :默认形参函数演示  
** 作者 : tsingke
** 时间 : 2019-10-8 / 14:29
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;



void func(int a, int b,int c)
{

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

}

void func_1(int a, int b=600, int c=800)
{

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

}






/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{

	


	int a = 1;


	int b = 2;
	int c = 3;

	int a_1 = 3;


	//func(a, b, c);

	func_1(a);
	func_1(a, b);
	func_1(a, b, c);





	system("pause");
	
	return 0;
}