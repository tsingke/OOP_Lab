/*************************************************
** 功能 : const本质：const栈常量与const全局区常量 能否被修改?
** 作者 : tsingke
** 时间 : 2019-11-11 / 23:36
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;


const int global = 100;

/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{

#if 1
	//情形1: const修饰的栈上的常量,通过指针可以间接实现对其修改

	const int  local = 10;//下面程序所有的local在编译时都被替换为10

	cout << "const local = " << local << endl;

	//意图通过指针修改这个常量

	int *p1 = (int*)(&local);

	*p1 = 20;

	cout << "const local = " << *p1 << endl;

	cout << "local地址   = " << &local << endl;
	cout << "p1指向的地址 = " << p1 << endl;

#endif

	//---------------------------------------------

#if 0
//情形2:const修饰的全局区上的常量,通过指针无法对其进行修改(编译时会报异常)

	int *p2 = (int*)(&global);

	cout << "const global = " << global << endl;

	*p2 = 200;

	cout << "const global = " << *p2 << endl;

	cout << "global地址  = " << &global << endl;
	cout << "p2指向的地址 = " << p2 << endl;

#endif


	system("pause");

	return 0;
}
