#include <iostream>

using namespace std;

class Furnitrue
{
public:
    void Show()
    {
        cout <<"m_weight " << m_weight << endl;
        cout <<"m_color" << m_color << endl;
    }
protected:
    int m_weight;
    int m_color;
};

class Sofa : virtual public Furnitrue
{
public:
    Sofa(int x=50, int y=100)
    {
        m_weight = x;
        m_color = y;
    }
    void sit()
    {
        cout << "Sofa can sit" << endl;
    }

};

class Bed : virtual public Furnitrue
{
public:
    Bed(int x=50, int y=100)
    {
        m_weight = x;
        m_color = y;
    }
    void sleep()
    {
        cout << "Bed can sleep" << endl;
    }
};

class SofaBed : public Sofa, public Bed
{
public:
    SofaBed(int x, int y)
    {
        m_weight = x;
        m_color = y;
    }
};

int main()
{
    SofaBed sb(100, 999);
    sb.sit();
    sb.sleep();
    sb.Show();
    return 0;
}
