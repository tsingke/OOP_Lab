```c++
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;

class complex
{
private:
    double real;
    double imag;

public:
    //===================静态多态: 函数重载========================
    complex();
    complex(double r, double i);//构造函数
    complex(const complex &r);
     ~complex();

    void print();
    void print()const;



    //===============静态多态: 运算符重载1-成员函数法===============

     //a.重载加法运算符+(双目运算符)-类内-类外均可重载
    complex operator+(const complex &other);


    //b.重载赋值运算符=(双目运算符)-只在类内重载

    complex operator=(const complex &other);

     //c.重载前++运算符(单目运算符)-类内-类外重载均可
    complex operator++();


     //d.重载后++运算符(单目运算符)-类内-类外均可重载
    complex operator++(int);


    //e.重载函数调用运算符()运算符(单目运算符)-只在类内重载
    double operator()();

   //===============静态多态: 运算符重载2-友元函数法===============

    //-重载输出运算符<< : 双目运算符,格式"cout<<" 左侧是一个输出流对象cout",只在类外重载
    friend ostream& operator<<(ostream &out, complex &t);

};


#endif // COMPLEX_H

```
