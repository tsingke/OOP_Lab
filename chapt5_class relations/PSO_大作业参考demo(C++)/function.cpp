/*************************************************
** 源文件   : function.cpp
** 功能说明 : Function Definations
** 创建时间 : 2019-11-22/12:54
/**************************************************/


#include "function.h"

/*------------------------------------------
*           测试函数源文件
--------------------------------------------*/


#include <cmath>
#include <cstdlib>


const double PI = 3.1415926;

//--------------------------一.单峰函数优化--------------------

//该函数的最优解[0,0,...,0],最佳适应度值为0.0
double sphere(double x[], int dim)
{
	int i;
	double value = 0.0;
	
	for (i = 0; i < dim; i++)
	{
		value += pow(x[i], 2);

	}
	return value;
}

//该函数的最优解[0,0,...,0],最佳适应度值为0.0,搜索范围:[-100, 100]
double SchwefelP12(double x[], int dim)
{
	int i, j;

	double value = 0.0;

	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			value += x[j] * x[j];

		}

	}

	return value;
}

//该函数的最优解[0,0,...,0],最佳适应度值为0.0,搜索范围:[-10, 10]
double SchwefelP22(double x[], int dim)
{
	double value1 = 0.0, value2 = 1.0;
	double value = 0.0;
	for (int i = 0; i < dim; i++)
	{
		value1 += fabs(x[i]);
		value2 *= fabs(x[i]);

	}
	value = value1 + value2;

	return value;

}

//该函数的最优解[0,0,...,0],最佳适应度值为0.0,搜索范围:[-10, 10]
double Rosenbrock(double x[], int dim)
{


	double value = 0.0;

	for (int i = 0; i < dim - 1; i++)
	{
		value += 100 * pow((x[i + 1] - (x[i] * x[i])), 2) + pow((x[i] - 1), 2);
	}

	return value;
}


//------------------多峰函数优化----------------------------
//该函数的最优解[0,0,...,0],最佳适应度值为0.0,搜索范围:[-100, 100]
double Schwefel2_26(double x[], int dim)
{
	double value = 0.0;

	for (int i = 0; i < dim; i++)
	{
		value += -1.0*x[i] * sin(sqrt(fabs(x[i])));
	}

	return value;

}
//该函数的最优解[0,0,...,0],最佳适应度值为0.0,,搜索范围:[-32, 32]
double Ackley(double x[], int dim)
{

	int i;
	double A = 0.0, B = 0.0;
	double value = 0.0;

	for (i = 0; i < dim; i++)
	{
		A += (x[i] * x[i]) / dim;

		B += cos(2 * PI*x[i]) / dim;

	}


	value += -20.0*exp(-0.2*sqrt(A)) - exp(B) + 20 + exp(1);

	return value;

}

//该函数的最优解[0,0,...,0],最佳适应度值为0.0,搜索范围:[-600, 600]
double Griewanks(double x[], int dim)
{

	int i;
	double A = 0.0, B = 1.0;//注意初始化B的值
	double value = 0.0;

	for (i = 0; i < dim; i++)
	{
		A += pow(x[i], 2) / 4000.0;

		B *= cos(x[i] / sqrt(i + 1));

	}

	value = A - B + 1.0;

	return value;
}
//该函数的最优解[0,0,...,0],最佳适应度值为0.0,搜索范围:[-5.12, 5.12]
double Rastrigin(double x[], int dim)
{

	int i;
	double value = 0.0;

	for (i = 0; i < dim; i++)
	{
		value += x[i] * x[i] - 10 * cos(2 * PI*x[i]) + 10;
	}

	return value;
}

//该函数的最优解[0,0,...,0],最佳适应度值为0.0
double Rastrigin_nc(double x[], int dim)
{
	int i;
	double y_i;

	double value = 0.0;

	for (i = 0; i < dim; i++)
	{

		if (fabs(x[i]) < 0.5) y_i = x[i];

		else y_i = round(2.0 * x[i]) / 2.0;

		value += y_i * y_i - 10 * cos(2 * PI*y_i) + 10.0;
	}

	return value;

}
//该函数的最优解[0,0,...,0],最佳适应度值为0.0,搜索范围:[-0.5, 0.5]
double Weierstrass(double x[], int dim)
{

	int i, k;
	double A = 0.0, B = 0.0;
	double value = 0.0;

	//计算A部分
	for (i = 0; i < dim; i++)
	{
		for (k = 0; k <= 20; k++)
		{
			A += pow(0.5, k)*cos(2 * PI*pow(3, k)*(x[i] + 0.5));
		}
	}

	//计算B部分

	for (k = 0; k <= 20; k++)
	{
		B += pow(0.5, k)*cos(2 * PI *pow(3, k)*0.5);
	}

	A = fabs(A - dim * B);

	value = A;

	return value;
}

//该函数的最优解[420.9687,420.9687,...,420.9687],最佳适应度值为0.0,搜索范围:[-500, 500]
double Schwefel(double x[], int dim)
{
	int i;

	double value = 0.0;
	double tmpsum = 0.0;

	for (i = 0; i < dim; i++)
	{
		tmpsum += x[i] * sin(sqrt(fabs(x[i])));
	}

	value += 418.9829*dim - tmpsum;

	return value;

}
//该函数的最优解[0,0,...,0],最佳适应度值为0.0
double Penalized(double x[], int dim)
{
	int i;
	double A = 0.0, B = 0.0;
	double tmp = 0.0;
	double value = 0.0;

	double *y=new double[dim] ;

	//计算y的值
	for (i = 0; i < dim; i++)
	{
		y[i] = 1 + 0.25*(x[i] + 1);
	}

	//计算A
	for (i = 0; i < dim - 1; i++)
	{

		A += pow(y[i] - 1, 2)*(1 + 10 * pow(sin(PI*y[i + 1]), 2));
	}

	A = (PI / dim)*(10 * pow(sin(PI*y[0]), 2) + A + pow(y[dim - 1] - 1, 2));

	//计算B
	for (i = 0; i < dim; i++)
	{
		if (x[i] > 10)
		{
			tmp = 100 * pow((x[i] - 10), 4);
		}
		else if ((x[i] >= -10) && (x[i] <= 10))
		{
			tmp = 0;
		}

		else
		{
			tmp = 100 * pow((-1.0*x[i] - 10), 4);
		}

		B += tmp;
	}

	value = A + B;

	delete[] y;

	return value;

}


