/*************************************************
** 功能 : 动态多态性--指哪打哪如何实现
** 作者 : tsingke
***************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;
class base
{

private:
  int a;
  int b;
  int c;
public:
  base()
  {
    cout<<"base() is called"<<endl;

  }
  void display()
  {
    cout<<"base-display() is called "<<endl;

  }
};

class derive: public base
{
private:
  int x,y,z;
public:
  derive()
  {
    cout<<"derive() is called"<<endl;
  }
};


/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{


  base father;

  derive son;



  //---------探索赋值兼容性：3种类型---------

  father = son;//赋值兼容性1

  //son = father;//错误， 父类对象不能赋值给派生类对象

  base *p = &son;//赋值兼容性2

  base &r = son;//赋值兼容性3



  father.display();//调用父类函数

  p->display();    //调用父类内的函数

  r.display();     //调用父类内的函数


  /*
   * 赋值兼容性存在的问题：无法通过父类指针访问到子类新添加的同名函数
   * 解决方法：在基类内设置同名函数为虚函数，即可实现“指哪打哪”的效果
   **/



  return 0;
}
