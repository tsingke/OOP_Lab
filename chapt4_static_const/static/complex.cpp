#include "complex.h"
#include <iostream>

//初始化静态数据成员
int complex::s=0;    //类外初始化,务必注意,如果将类采用多文件编程时,静态成员变量的定义不要放在.h文件中,放在.cpp文件中,否则会引发多重定义问题.
int complex::count=0;


//-------c/c++中的static本质：持久化存储，实现数据共享功能-------------
using namespace std;

//extern int global;

complex::complex(int px, int py):x(px),y(py)
{
  cout<<"Constructor is called"<<endl;
  count++;
  cout<<"cout = "<<count<<endl;

}

complex::~complex()
{
  cout<<"destructor is called"<<endl;
  count--;
  cout<<"cout = "<<count<<endl;

}

void complex::display()
{
  cout<<"x = "<<x<<endl;
  cout<<"y = "<<y<<endl;

  showcount();//普通函数可以直接访问静态函数

}

void complex::showcount()//本质是类外的全局函数
{
   cout<<"count = "<<count<<endl;

  //this->x=2;//静态成员函数无法访问非静态成员

   //display();//会报错，不允许在静态函数访问非静态函数（因为普通函数背后是对象）

}
