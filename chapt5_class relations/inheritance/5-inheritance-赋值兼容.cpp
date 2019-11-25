#include <iostream>

using namespace std;

//赋值兼容

//1派生类对象可以赋值给基类对象
//2派生类对象可以初始化基类的引用
//3派生类对象的地址可以赋值给指向基类的指针

class Sharp
{
public:
    Sharp(int x=0, int y=0)
        :m_x(x),m_y(y)
    {

    }
    void Draw()
    {
        cout << "Sharp::" << "(" << m_x << "," << m_y << ")" << endl;
    }
protected:
    int m_x;
    int m_y;
};

class Circle : public Sharp
{
public:
    Circle(int x=0, int y=0, int r=0)
        :Sharp(x,y),m_radius(r)
    {

    }
    void Draw()
    {
        cout << "Circle::" << "(" << m_x << "," << m_y << ")" << "radius" << m_radius << endl;
    }
protected:
    int m_radius;
};

int main()
{
    //1.派生类对象可以赋值给基类对象
    //Sharp s(1,2);
    //s.Draw();
    //Circle c(3,4,5);
    //c.Draw();
    //
    //s = c;
    //s.Draw();


//2.派生类对象可以初始化基类的引用
//    Circle c(3,4,5);

//    Sharp & rs = c;
//    rs.Draw();


    //3.派生类对象的地址可以赋值给指向基类的指针
    //Circle c(3,4,5);
    //Sharp *ps = &c;
    //ps->Draw();


    //int a = 10;
    //int *pi = &a;
    //char *pc = &a; //这样是完全安全的
    //
    //char ch = 'a';
    //int *pi = &ch;//这样是不安全的





    return 0;
}
