/*************************************************
** 功能 : 引用的使用演示案例demo 
** 作者 : tsingke
** 时间 : 2019-10-8 / 10:08
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;


double sum(int x, int &y)
{

	x++;
	y++;

	return x + y;
}


int& sumref(int x,int &y)
{

	y = x + y;



	return y;
	//注意:不要返回局部变量的引用,因为局部变量离开所在函数就被系统释放回收了,即使起别名也没有任何使用价值.
	// 可以返回某个类型为引用的形参,例如这里的y就是一个引用形参类型,可以返回.


}


int func(int *p, int &r,int o)
{

	*p = 666;//通过指针改变指向的数值
	 r = 888;//通过引用改变指向的数值
	 o = 999;


	 cout << "指针*p的数值= " << *p << endl;
	 cout << "引用r的数值= " << r << endl;
	 cout << "整型o的数值= " << o << endl;

	return 0;
}

/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{

	//1. 什么是引用:变量的别名

	int a1 = 100;
	int a2 = 200;

	int &r = a1;//声明时就要给引用初始化
	     r = a2;


	cout << "a的地址:" << &a1 << endl;
	cout << "r的地址:" << &r << endl;


	//2.哪些量不可以是引用

	//void va;    //不可以建立void变量的引用
	//int &&r = a;//不可以建立引用的引用
	//int & *p = a;//不允许使用指向指针的引用
	//int & arry[10] = a;//不允许使用引用的数组



	//3. 引用的作用1: 做函数的形参,做函数的返回类型

	sum(a1, a2);

	cout << "a1的数值= " << a1 << endl;
	cout << "a2的数值= " << a2 << endl;


   //4. 引用的作用2:作为函数的返回类型(例如:cin>>x执行完后返回的是cin对象的引用,还是cin)




	sumref(a1, a2);//独立的函数调用语句

	int s = sumref(a1, a2) + 8;//引用作为操作数

	sumref(a1, a2) = 3000;//引用作为左边的数值


	
	//5. 引用和指针的区别

	//引用:变量的别名, 本身直接操作指向的数据
	//指针:带有类型的地址,远程间接操作指向的数据
	
	int m = 1;
	int n = 2;
	int o = 3;

	func(&m, n,o);

	cout << "m = " << m << "  n= " << n << endl;


	system("pause");
	
	return 0;
}