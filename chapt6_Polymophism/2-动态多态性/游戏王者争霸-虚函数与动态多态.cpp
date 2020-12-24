/*************************************************
** 功能 : 动态多态实践应用： 王者争霸游戏模拟  
** 作者 : tsingke
/**************************************************/


//动态多态：借助虚函数实现

//动态多态条件: 公有继承（public）, 原型相同（基类与子类某个函数原型相同） 
//实现的结果  ：指哪打哪

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int killDragon = 0;
int killLion = 0;
int killTiger = 0;

const int MaxDragon = 5;
const int MaxLion = 20;
const int MaxTiger = 30;

const int iter = 100;

//-------------------基类：所有游戏角色的基类------------------------
class Canimal
{
protected:

	double lifeValue; // 生命力，自身的寿命
	double power;     // 攻击力，对其他动物


public:
	virtual void Attack(Canimal *other) {};  //虚函数: 自己主动攻击别人
	virtual void Fightback(Canimal *own) {};//虚函数: 攻击别人时被别人反击自己
	virtual void Hurted(int power) {};       //虚函数: 自己被别人主动攻击

};

//-------------------具体类: dragon龙类------------------------
class Cdragon : public Canimal
{
public:
	Cdragon(double _value = 100, double _power = 50)
	{
		this->lifeValue = _value;
		this->power = _power;
	}

	//自己被别人攻击
	void Hurted(int power)
	{

		this->lifeValue -= power;
		if (lifeValue <= 0)
		{
			cout << "龙被打死了 ";
			killDragon++;
		}

	}

	//被反击:攻击别人时,被别人反击
	void Fightback(Canimal *p)
	{
		p->Hurted(0.5*power);

	}

	//主动攻击: 自己攻击别人,使别人受伤,自己也受到一些对方的反击伤害
	void Attack(Canimal *other)
	{
		other->Hurted(power);  //攻击别人,使别人受伤
		other->Fightback(this);//被别人反击,自己也受伤
	}

};

//-------------------具体类: CLion 狮子类------------------------

class Clion : public Canimal
{
public:
	Clion(double _value = 100, double _power = 30)
	{
		this->lifeValue = _value;
		this->power = _power;
	}


	//自己被别人攻击
	void Hurted(int power)
	{

		this->lifeValue -= power;
		if (lifeValue <= 0)
		{
			cout << "狮子被打死了 ";
			killLion++;
		}

	}

	//被反击:攻击别人时,被别人反击
	void Fightback(Canimal *p)
	{
		p->Hurted(0.5*power);

	}

	//主动攻击: 自己攻击别人,使别人受伤,自己也受到一些对方的反击伤害
	void Attack(Canimal *other)
	{
		other->Hurted(power);  //攻击别人,使别人受伤
		other->Fightback(this);//被别人反击,自己也受伤

	}

};
//-------------------具体类: CTiger 老虎类------------------------
class Ctiger : public Canimal
{
public:
	Ctiger(double _value = 100, double _power = 20)
	{
		this->lifeValue = _value;
		this->power = _power;
	}


	//自己被别人攻击
	void Hurted(int power)
	{

		this->lifeValue -= power;
		if (lifeValue <= 0)
		{
			cout << "老虎被打死了 ";
			killTiger++;
		}

	}

	//被反击:攻击别人时,被别人反击
	void Fightback(Canimal *p)
	{
		p->Hurted(0.5*power);

	}

	//主动攻击: 自己攻击别人,使别人受伤,自己也受到一些对方的反击伤害
	void Attack(Canimal *other)
	{
		other->Hurted(power);  //攻击别人,使别人受伤
		other->Fightback(this);//被别人反击,自己也受伤
	}

};



//=============================主函数================================
int main()
{

	srand((unsigned)time(NULL));

	//1. 初始化一群动物对象
	Cdragon dragon[MaxDragon];//龙类对象数组
	Clion lion[MaxLion];                //狮子类对象数组
	Ctiger tiger[MaxTiger];            //老虎类对象数组

	//2. 动物开始随机厮杀
	cout << "王者争霸游戏已开启,请按任意键开始>>>>>" << endl;
	getchar();

	for (int i = 0; i < iter; ++i)
	{
		cout << "开始第" << i + 1 << "轮厮杀: ";

		switch (rand() % 2)
		{
		case 0: //龙攻击狮子
		{
			//随机选择一个龙和一头狮子
			int id1 = rand() % MaxDragon;
			int id2 = rand() % MaxLion;

			dragon[id1].Attack(&lion[id2]);
		}

		break;
		case 1: //狮子攻击老虎
		{
			//随机选择一个狮子和一只老虎
			int id1 = rand() % MaxLion;
			int id2 = rand() % MaxTiger;

			lion[id1].Attack(&tiger[id2]);
		}  break;

		case 2: // 老虎攻击龙
		{
			//随机选择一个老虎和一条龙
			int id1 = rand() % MaxTiger;
			int id2 = rand() % MaxDragon;

			tiger[id1].Attack(&dragon[id2]);
		}  break;

		}//switch

		cout << "kill掉" << (killDragon + killLion + killTiger) << "个怪物" << endl;



	}//for


	cout << "-------------------------" << endl;
	cout << "游戏结束!" << endl<<endl;

	cout << "共kill掉" << killDragon << "条龙" << endl;
	cout << "共kill掉" << killLion << "头狮" << endl;
	cout << "共kill掉" << killTiger << "只虎" << endl;


	system("pause");
	return 0;
}
