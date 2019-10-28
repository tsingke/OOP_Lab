#include <iostream>
#include "student.h"
using namespace std;

int main()
{
    char *name =new char[20];

    name="Bill Gates";

    student stu1(name,60,1);
    stu1.display();

    student stu2=stu1;
    stu2.display();






    return 0;
}
