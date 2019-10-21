/*************************************************
** 功能 : 内联函数的使用  
** 作者 : tsingke
** 时间 : 2019-9-24 / 00:42
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <cmath>

using namespace std;

const int run = 100000000;



 int multiply_1(int x, int y)
{


	 return x*y;


}


 inline int multiply_2(int x, int y)
{


	 return x*y;



}
/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{

	int t=0;


	int a = 1;
	int b = 2;


	/*----------------------------------*
	            普通函数调用时间统计
	*-----------------------------------*/
	int ss_1, ss_2;

	clock_t start_1, end_1;

	start_1 = clock();

	while (t<run)
	{
		 ss_1 = multiply_1(a++, b++);

		//cout << a << "^2 + " << b << "^2 = " << ss << endl;
		 t++;

	}
	end_1 = clock();


	cout << "普通函数执行总时间: " <<1.0*(end_1 - start_1)  << endl;


	/*----------------------------------*
			内联函数调用时间统计
    *-----------------------------------*/
	clock_t start_2, end_2;

	start_2 = clock();

	t = 0;
	while (t < run)
	{
		ss_2 = multiply_2(a++, b++);
		//cout << a << "^2 + " << b << "^2 = " << ss << endl;
		t++;

	}
	end_2 = clock();


	cout << "内联函数执行总时间: " << 1.0*(end_2 - start_2) << endl;





	system("pause");
	
	return 0;
}