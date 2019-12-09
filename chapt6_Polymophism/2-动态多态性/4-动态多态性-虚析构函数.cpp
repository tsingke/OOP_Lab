/*************************************************
** 功能 : 动态多态性--虚析构函数(一虚全虚)
** 作者 : tsingke
***************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

//--------------------父类----------------------------

class base
{

private:
	int a;
public:
	base()
	{
		cout << "base() is called" << endl;

	}
	//~base(){}// 
	virtual ~base()
	{
		cout << "~base() is called" << endl;
	}

	virtual void print()
	{
		cout << "base-print() is called" << endl;
	}


};

//--------------------子类----------------------------
class derive : public base
{
private:
	int *id;
public:
	derive()
	{
	
		id = new int[10];
		cout << "derive() is called" << endl;
	}
	~derive()//如果基类析构函数为虚函数,则子类的析构函数全都自动变为虚函数
	{
		cout << "~derive() is called" << endl;
		if (id!=NULL)
		{
			delete[] id;
		}
	}

	virtual void print() //公有继承,长相相同
	{
		cout << "derive-print() is called" << endl;
	}

};


/*----------------------------------*
		  Main Function
*-----------------------------------*/

int main()
{


	base *p = new derive; //通过基类指针创建无名对象

	p->print();          // 通过虚函数实现"指哪打哪"的目的

	delete p;             //通过基类指针释放无名对象


	return 0;
}
