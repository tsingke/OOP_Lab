

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