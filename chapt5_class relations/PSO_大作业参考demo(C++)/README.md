

** 粒子群优化算法-作业源码参考


```c++



#ifndef _PSO_H_
#define _PSO_H_

const int DIMENSION=30;   //函数优化的维度(自变量个数),可以是10维,20维,30维度,...100维


/*--------------------------------------------------*
                   PSO类定义--粒子个体类
*---------------------------------------------------*/

class PSO
{
	//------------------PSO类数据成员---------------
private:
	//1.粒子个体信息
	double x[DIMENSION];//粒子位置向量
	double v[DIMENSION];//粒子速度向量
	double fitness;//粒子适应度数值

	//2.粒子局部最优信息
	double pbestx[DIMENSION];//粒子局部最优位置
	double pbestfitness; //粒子局部最优适应度数值

	//3.粒子群全局最优信息(共享信息)
	static double gbestx[DIMENSION];//全局最优位置
	static double gbestFintness;//全局最优适应度值

	//------------------PSO类函数成员---------------

public://粒子个体的行为信息`

	PSO();//构造函数
	~PSO();//析构函数
	
	//普通函数(获取粒子个体的相关信息)
	double* getX();//获得粒子的位置向量
	double* getV();//获得粒子的速度向量
	double& getFitness();//获得粒子的适应度
	double* getPbestX();//获得粒子的局部最优位置向量
	double& getPbestFitness();//获得粒子的局部最优适应度数值

	//普通函数:初始化位置和速度向量
	void initi(double xmin, double xmax, double vmin, double vmax);//在搜索范围内初始化当前粒子的个体位置和速度向量

	//普通函数:计算粒子的适应度(待优化的函数的值)
	double computeFitness(double x[], int dim);

	//普通函数:更新子局部最优和全局最优信息
	void updatePbestX();//更新粒子个体局部最优位置
	void updateGbestX();//更新粒子群体的全局最优位置

	//普通函数:更新粒子的速度和位置向量-生成新的位置
	void updateV(int iter);
	void updateX(int iter);

	//-----------------------------------------------------

	//静态函数:获取全局最佳粒子信息
	static double* getGbestX();//获得全局最佳位置向量
	static double& getGbestFitness();//获得全局最佳适应度数值

	//静态函数:输出全局最佳粒子信息
	static void printGbestX();
	static void printGbestFitness();
};

#endif

```

pso类的实现

```c++


#include <iostream>
#include <cmath>
#include <cstdlib>
#include "PSO.h"
#include "function.h"

using namespace std;


//初始化类中的静态数据成员
double PSO::gbestx[DIMENSION] = {0.0};//全局最优位置初始化
double PSO::gbestFintness=pow(2,1024);//全局最优适应度值初始化,一个较大的值


//外部全局变量导入本文件,以供使用
extern int MAX_ITER;

extern double xmax;
extern double xmin;


extern double vmax;
extern double vmin;

//--------------------PSO类的函数定义------------------------------


PSO::PSO()
{
	//cout << "调用构造函数完成初始化" << endl;
}


PSO::~PSO()
{
	//cout << "调用析构函数完成对象释放" << endl;
}

double * PSO::getX()
{
	return x;//返回位置首地址
}

double * PSO::getV()
{
	return v;
}

double & PSO::getFitness()
{

	return fitness;
}

double * PSO::getPbestX()
{
	return pbestx;
}

double & PSO::getPbestFitness()
{
	return pbestfitness;
}

void PSO::initi(double xmin, double xmax, double vmin, double vmax)
{
	//初始化粒子个体的位置和速度
	for (int i = 0; i < DIMENSION; i++)
	{
		x[i] = xmin + (rand() / (32767 + 1.0)) *(xmax - xmin);
		v[i] = vmin + (rand() / (32767 + 1.0))*(vmax - vmin);
	}


	//计算当前粒子最初的适应度
	fitness = computeFitness(x,DIMENSION);


	//初始化粒子最初的局部最优位置和适应度
	for (int i = 0; i < DIMENSION; i++)
	{
		pbestx[i] = x[i];
	}

	pbestfitness = fitness;

}


//适应度:某个函数f的数值(计算结果越小说明对应的解越好)
double PSO::computeFitness(double x[], int dim)
{
	fitness = sphere(x, dim);//函数Sphere作为测试函数,其他函数自行测试
	//fitness = Rosenbrock(x, DIMENSION);//函数Rosenbrock作为测试函数
	//fitness = Ackley(x, DIMENSION);
	//fitness = Griewanks(x, DIMENSION);


	return fitness;
}

//更新局部最优位置
void PSO::updatePbestX()
{
	if (fitness<pbestfitness)
	{
		pbestfitness = fitness;

		for (int i = 0; i < DIMENSION; i++)
		{
			pbestx[i] = x[i];
		}	
	}
}


//更新全局最优位置
void PSO::updateGbestX()
{
	if (pbestfitness<=gbestFintness)
	{
		gbestFintness = pbestfitness;

		for (int i = 0; i < DIMENSION; i++)
		{
			gbestx[i] = pbestx[i];
		}
	}
	else;
}

void PSO::updateV(int iter)
{
	//更新公式参数
	double w = 0.9 - 0.5*iter / MAX_ITER;
	double c1 = 2.0;
	double c2 = 2.0;

	//注意r1,r2是随机生成的小数,需要将其放在for内,每次都产生新的随机数,随机性越高,求解精度越高
	for (int i = 0; i < DIMENSION; i++)
	{
		v[i] = w * v[i] + c1 *rand()/(32767 + 1.0)*(pbestx[i] - x[i]) + c2 * rand() / (32767 + 1.0)*(gbestx[i] - x[i]);
	
		//速度越界判断
		if (v[i]<=vmin || v[i]>=vmax)
		{
			v[i] = (vmax - vmin)*rand() / (32767 + 1.0);

		}
		else continue;
	}

}


void PSO::updateX(int iter)
{
	for (int i = 0; i < DIMENSION; i++)
	{
		x[i] = x[i] + v[i];

		//位置越界判断
		if (x[i] <= xmin || x[i] >= xmax)
		{
			x[i] = xmin+(xmax - xmin)*double(rand()/RAND_MAX);

		}
		else continue;
	}

}

//-----------------静态函数的定义--------------------

double * PSO::getGbestX()
{
	return gbestx;
}

double & PSO::getGbestFitness()
{
	return gbestFintness;
}

void PSO::printGbestX()
{
	cout <<endl<<"输出当前最好的解:" << endl<<endl;

	for (int dim = 0; dim < DIMENSION; dim++)
	{
		cout << "gbestX[" << dim << "] = " << gbestx[dim] << endl;

	}
	cout << endl;
}

void PSO::printGbestFitness()
{
	cout << "全局最优解的精度: " << gbestFintness << endl;
	cout << endl;
}



```


主函数

```c++
/*************************************************
** 功能 : 粒子群优化算法演示
** 作者 : tsingke
** 时间 : 2019-11-22 / 10:54
***************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <windows.h>

#include "PSO.h"
#include "function.h"

using namespace std;

//算法迭代参数设置
int POPSIZE = 40;        //种群个体数目
int MAX_ITER = 7500;     //迭代次数


double accuracy = 1e-60; //搜索精度,误差精度,可以自己改


//搜索范围设置(位置范围,速度范围)
double xmax = 10;
double xmin = -10;

double vmax = 10;
double vmin = -10;

bool success = 0;
/*----------------------------------*
          Main Function
*-----------------------------------*/

int main()
{

	srand((unsigned)time(NULL));//产生伪随机数种子

	//1. 在堆上生成PSO类的对象数组,即粒子种群,共POPSIZE个个体
	PSO *swarm=new PSO[POPSIZE];


	//2. 初始化粒子群内所有粒子个体的信息(位置,速度,..等)
	for (int i = 0; i < POPSIZE; i++)
	{
		swarm[i].initi(xmin,xmax,vmin,vmax);
	}

	//3. 循环迭代-搜索目标函数的全局最优解

	cout << "---------------算法开始迭代-------------------" << endl;

	for (int iter = 0; iter < MAX_ITER; iter++)
	{
		for (int id = 0; id < POPSIZE; id++)
		{
			swarm[id].updatePbestX();//更新个体局部最优位置
			swarm[id].updateGbestX();//更新群体全局最优位置

	
			swarm[id].updateV(iter);//更新个体速度

			swarm[id].updateX(iter);//更新个体位置

			swarm[id].computeFitness(swarm[id].getX(),DIMENSION);//计算个体适应度

	
		}

		//判断是否达到要求
		if (PSO::getGbestFitness() <= accuracy)//达到设定的精度,中途输出结果,并停止后续迭代
		{
			cout << "搜索到符合精度的解(如下),算法停止搜索" << endl;

			PSO::printGbestX();       //输出全局最优解向量		
			PSO::printGbestFitness(); //输出全局最优解的精度
			success = 1;
			break;//跳出循环,停止迭代
		}


		cout << "迭代到第" << iter << "代, 本代最佳适应度数值(误差精度)= " << PSO::getGbestFitness()<<endl;

	}

	//4. 输出实验结果(未达到设定精度,依然输出结果)
	if (success==0)
	{

		PSO::printGbestX();//输出全局最优解向量	

		PSO::printGbestFitness();//输出搜索精度

	}

	//5. 释放申请的堆上的动态存储空间
	delete[] swarm;



	system("pause");
	
	return 0;
}
```
