/*************************************************
** 头文件   : function.h
** 功能说明 : 测试函数
** 创建时间 : 2019-11-22/11:41
/**************************************************/

#ifndef _FUNCTION_H_
#define _FUNCTION_H_


//------------单峰函数(函数只有一个极值点)----------------

double sphere(double x[], int dim);

double SchwefelP12(double x[], int dim);

double SchwefelP22(double x[], int dim);

double Rosenbrock(double x[], int dim);


//------------多峰函数(函数有多个极值点)----------------

double Schwefel2_26(double x[], int dim);

double Ackley(double x[], int dim);

double Griewanks(double x[], int dim);


double Rastrigin(double x[], int dim);

double Rastrigin_nc(double x[], int dim);


double Weierstrass(double x[], int dim);

double Schwefel(double x[], int dim);

double Penalized(double x[], int dim);



	
#endif

