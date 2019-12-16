#include <iostream>
using namespace std;

int main()
{
    int i=100;
    int j=200;

    //1.指向常量的指针：指向的量是常量，故*p1不可变，但p1可变
#if 1

    const int *p1;

    *p1 = j;//错误
    p1=&j;  //正确


#endif

    //2.常指针：指针自己是常量， 故p2不可变， 但*p2可变
#if 1

    int* const p2=&i;

     p2 = &j; //错误
    *p2=j;    //正确


#endif

    //3.指向常量的常指针： 指针是常量，指针指向的也是常量，故都不能修改。
#if 1

    int const * const p3 =&i;

    p3=&j;//错误
    *p3=j;//错误

#endif
    return 0;
}
