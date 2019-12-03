#include "complex.h"



//-----------------------成员函数-------------------------

complex::complex()
{

}

complex::complex(double r, double i)
{
    this->real =r;
    this->imag =i;
}

complex::complex(const complex &r)
{
    this->real =r.real;
    this->imag = r.imag;
}

complex::~complex()
{

}

void complex::print() const
{


}

complex complex::operator+(const complex &other)
{

    complex temp;

    temp.real = this->real + other.real;
    temp.imag = this->imag + other.imag;

    return  temp;

}

//赋值运算符=
complex complex::operator=(const complex &other)
{
    this->real = other.real;
    this->imag = other.imag;
}

//前++
complex complex::operator++()
{
    ++this->real;
    ++this->imag;

    return *this;

}

//后++
complex complex::operator++(int)
{
    complex temp;//

    temp.real = this->real++;
    temp.imag=this->imag++;

    return  temp;

}

//函数调用符
double complex::operator()()
{
    double sum = this->real * this->real + this->imag *this->imag;

    return  sum;

}


//-----------------------友元函数-------------------------
ostream & operator<<(ostream &out, complex &t)
{
    out<<t.real<<"+" <<t.imag<<"i"<<endl;
}




