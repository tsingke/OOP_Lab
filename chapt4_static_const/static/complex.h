#ifndef COMPLEX_H
#define COMPLEX_H

class complex
{

private:
  double x;
  double y;
  static int count;//私有的静态成员变量

public:
  complex(int px,int py);
  ~complex();
  void display();

  static int s;//公有的静态成员变量
  static void showcount();//
};

//int complex::s=0;    //类外初始化,务必注意,如果将类采用多文件编程时,静态成员变量的定义不要放在.h文件中,放在.cpp文件中,否则会引发多重定义问题.
//int complex::count=0;//类外初始化,必注意,如果将类采用多文件编程时,静态成员变量的定义不要放在.h文件中,放在.cpp文件中,否则会引发多重定义问题.

#endif // COMPLEX_H
