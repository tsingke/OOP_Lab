#include <iostream>
#include "complex.h"
using namespace std;


//int global=10;   //可以在整个程序的多个文件内共享的全局变量，只要其他位置将其声明为外部变量即可，exter int global;

static int s_ga=0;//仅在本文件内进行共享的全局变量，外部文件无法访问外联性，external link

void func(int t)
{
  static int s_la=0;//static 修饰局部变量，la此时就具有了持久化存储能力，直到程序结束一直存在；初始化工作只在开始执行1次，之后不再初始化

  s_la=s_la+t;

  cout<<"s_la= "<<s_la<<endl;

}

int main()
{
 //-------------------1-----------------------
#if 1
  //1. 测试静态全局变量的本质

  s_ga=2;

  s_ga++;

  cout<<"s_ga="<<s_ga<<endl;

#endif

 //-------------------2-----------------------
#if 1
  //2. 测试静态局部变量的本质

  for (int i = 0; i < 10; ++i)
    {
      func(i);
    }
  cout << "Hello World!" << endl;
#endif

  //------------------3------------------------

#if 1

  //3. static 在类中的使用（静态数据成员、静态成员函数）

  //静态变量：本质为外部的全局变量，现在将其拉到类内，实现封装
  //静态函数：本质为外部的全局函数，专门为访问类内静态变量而设置。

  complex ca(2,5);
  complex cb(1,4);


  //3.1 类直接访问公有静态数据成员
  cout<<"complex::s= "<<complex::s<<endl;

  //3.1 对象访问公有静态数据成员
  cout<<"ca.s = "<<ca.s<<endl;
  cout<<"cb.s = "<<cb.s<<endl;

  //~~~~

  //3.2 类通过静态成员函数访问私有静态数据成员（专门为类服务的）
  complex::showcount();

  //3.2 对象通过访问静态成员函数访问私有静态数据
  ca.showcount();
  ca.display();

#endif

  //cout<<"complex::count"<<complex::count<<endl;
  return 0;
}
