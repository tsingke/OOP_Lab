/*************************************************
** 功能 : namespace  
** 作者 : tsingke
** 时间 : 2019-9-23 / 21:33
***************************************************/

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <string>

using namespace std;

namespace one
{

	int id;
	double salary;
}


namespace two
{

	int id;
	double salary;
}

namespace three
{

	int id;
	double salary;
	string address;
}
/*----------------------------------*
          Main Function
*-----------------------------------*/

using namespace one;

int main()
{


	/*-全部导入法-*/
	id = 2018;

	salary = 100000;


	/*-随用随取法-*/

	two::id = 2019;
	two::salary = 50000;
	
    

	/*-部分导入法-*/

	using three::id;

	id = 100;

	cout << "one::id = "<< one::id << endl;

	id = 999999;
	cout << "two::id = " <<id<< endl;

	cout << "one::id = "<< one::id << endl;

	//address = "sdnu";
	three::address = "sdnu";


	cout << three::address << endl;



	system("pause");
	
	return 0;
}