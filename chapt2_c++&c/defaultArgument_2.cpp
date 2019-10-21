/*************************************************
** 功能 : 函数默认形参演示  
** 作者 : tsingke
** 时间 : 2019-9-23 / 23:29
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

void plot(int x , int y , int z = 0, char color = 'B');


//void plot(int x, int y, int z, char color)
//{
//
//	cout << "坐标x= " << x << endl;
//	cout << "坐标y= " << y << endl;
//	cout << "坐标z= " << z << endl;
//
//	cout << "颜色 c= "  <<color << endl ;
//
//}



//void plot(int x=0, int y=1, int z=0, char color='B')
//{
//
//	cout << "------图形的基本信息如下所示-------" << endl ;
//	cout << "坐标x= " << x << endl;
//	cout << "坐标y= " << y << endl;
//	cout << "坐标z= " << z << endl;
//
//	cout << "颜色 c= " << color << endl;
//
//}




/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	

	int a = 3, b = 4, c = 5;
	char color = 'R';

	plot(a, b, c, color);//一一对应的方式

	plot(a, b);//
	




	system("pause");
	
	return 0;
}



//定义带默认形参的函数时,不要带上默认值,只在声明时带上!!!!
void plot(int x, int y, int z, char color)
{

	cout << x << y << z << color<< endl;


}