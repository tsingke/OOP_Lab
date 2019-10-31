#include <iostream>

using namespace std;

class date
{
    int year;
    int month;
    int day;

public:
    date(int y,int m,int d) ;
    ~date();
    void display();
    friend void birthdayCheck(date &r1,date &r2);// 友元“流浪”函数的声明 
};

date::date(int y, int m, int d)
{
   this->year=y;
    this->month=m;
            this->day=d;
   cout<<"this is a constructor function " <<endl;
}

date::~date()
{
   cout<<"this is a deconstrucor"<<endl ;
}

void date::display()
{
   cout<<year<<"年-"<<month<<"月-"<<day<<"日"<<endl;
}

void birthdayCheck(date &r1,date &r2)
{

    if((r1.year==r2.year)&&(r1.month==r2.month)&&(r1.day==r2.day))
    {
        cout<<"是同一天生日"<<endl;
    }
    else
    {
        cout<<"不是同一天生日"<<endl;
    }
}

int main()
{


    date zhang(2000,10,1);
    date wang(2000,10,1);

    zhang.display();

    wang.display();


    birthdayCheck(zhang,wang);

    return 0;//

}
