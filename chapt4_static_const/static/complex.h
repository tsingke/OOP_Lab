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

//int complex::s=0;    //类外初始化
//int complex::count=0;//类外初始化;

#endif // COMPLEX_H
