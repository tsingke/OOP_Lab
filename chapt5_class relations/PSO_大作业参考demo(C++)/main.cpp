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


double accuracy = 1e-100; //搜索精度,误差精度


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


		cout << "迭代到第" << iter << "代, 本代最佳适应度数值= " << PSO::getGbestFitness()<<endl;

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