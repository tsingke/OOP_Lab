/*************************************************
** 功能 : const demo
** 作者 : tsingke
** 时间 : 2019-9-24 / 08:33
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;


int sum(const int *p1, const int *p2)
{
	//*p1 = 222;


	return (*p1 + *p2);

}


/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{

	


	int a = 666;
	int b = 888;

	int c=sum(&a, &b);


	cout << "c= " << c << endl ;





	system("pause");
	
	return 0;
}