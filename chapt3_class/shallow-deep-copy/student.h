#ifndef STUDENT_H
#define STUDENT_H

//析构函数的作用:
/***
 *
 * 完成对象销毁前的清理工作,释放构造器申请的堆空间
 * 无返回类型
 * 自动被调用
 * 不能被重载,因为析构函数本身没有任何参数,所以"同名不同参"的条件永远无法被满足)
 */

class student
{
public:
    student();
    student(char*na,int age,int gender);

    student(const student &r);
    ~student();
    void display();

private:
    char *name;
    int age;
    bool gender;
};

#endif // STUDENT_H
