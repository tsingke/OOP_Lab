
```cpp
#include <iostream>
#include <fstream>
#include <cstdlib> //qsort在此头文件中声明

using namespace std;

//---------------------------------------

const int MAX_NUM = 1000;
int a[MAX_NUM]; //存放文件中读入的整数

int MyCompare(const void * e1, const void * e2)
{ //用于qsort的比较函数
     return *((int *)e1) - *((int *)e2);
}


int main()
{
    int total = 0;//读入的整数个数
    
     //-----------------------建立文件输入流---------------------------------
     
    ifstream srcFile("in.txt",ios::in); //创建输入流对象srcFile，以文本模式打开in.txt备读
    if(!srcFile) { //打开失败
        cout << "error opening source file." << endl;
        return 0;
    }
    
    //-------------------------建立文件输出流-------------------------------
    ofstream destFile("out.txt",ios::out); //创建输出流对象destFile，以文本模式打开out.txt备写
    if(!destFile) {
        srcFile.close(); //程序结束前不能忘记关闭以前打开过的文件
        cout << "error opening destination file." << endl;
        return 0;
    }
     //-------------------------文件读写操作-------------------------------
    int x;   
    
    // 1. 将文件数据依次读入到内存
    while(srcFile >> x) //可以像用cin那样用ifstream对象
        a[total++] = x;
        
    // 2. 数据处理
    qsort(a,total,sizeof(int),MyCompare); //排序
    
    // 3. 将处理后的数据写入到文件
    for(int i = 0;i < total; ++i)
        destFile << a[i] << " "; //可以像用cout那样用ofstream对象
        
    destFile.close();
    
    srcFile.close();
    
    return 0;
}
```
