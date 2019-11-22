
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
