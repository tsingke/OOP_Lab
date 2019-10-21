/*************************************************
** 功能 : 构造函数课堂演示
** 作者 : tsingke
** 时间 : 2019-10-21 / 18:18
***************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

class date
{
public:

    void inition(int y,int m, int d);
    date(); //无参构造函数

    date(int y, int m=1, int d=1);//有参构造函数(可以给定默认值)

    date(const date &r);//拷贝构造函数

    void display();

    ~date();

private:
    int year;
    int month;
    int day;
};

void date::inition(int y, int m, int d)
{
    this->year =y;
    this->month =m;
    this->day=d;
}

date::date()
{
    cout << "无参构造函数被调用" << endl;

}

date::date(int y,int m, int d)
{
    year = y;
    month = m;
    day = d;

    cout << "有参构造函数被调用" << endl;
}

date::date(const date & r)
{
    this->year = r.year;
    this->month = r.month;
    this->day = r.day;

    cout << "拷贝构造函数被调用" << endl;

}

void date::display()
{
   cout<<year<<"-"<<month<<"-"<<day<<endl;

   //cout<<"指针this指向地址:"<<this<<endl;

}


date::~date()
{
    cout << "*析构函数调用:" <<this<<endl;


}



/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{

    date a;//对象a
    cout<<"对象a的地址:"<<&a<<endl;

    a.display();

    date b(2019);//对象b
    b.display();


    date c(b);//对象c
    c.display();



    return 0;

}


