/*************************************************
** 功能 : 浅拷贝-深拷贝代码演示  
** 作者 : 
** 版本 : 2019-10-29 / 19:18
** 版权 : GNU General Public License(GNU GPL)
/**************************************************/

#include <iostream>
#include <cstdlib>
#include "student.h"


using namespace std;



/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{
	char *name = new char[20];

	strcpy(name, "bill gates");
	
	student zhang(2019,name);

	student wang = zhang;//调用系统默认的拷贝构造函数



	zhang.display();

	wang.display();





	system("pause");
	
	return 0;
}