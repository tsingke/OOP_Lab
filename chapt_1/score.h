#pragma once
/*************************************************
* Head File   : SCORE.h
* File Usage  : ѧ������ϵͳͷ�ļ�
* Create Time : v1.0
/**************************************************/

#ifndef __SCORE_H__
#define __SCORE_H__


#include <stdio.h>

/*----------------------------------*
	   ѧ����Ϣ-�ṹ�����
*-----------------------------------*/

typedef struct student
{
	char number[10];  //ѧ��
	char name[10];    //����
	float dailyScore;   //ƽʱ�ɼ�
	float finalScore;   //��ĩ�ɼ�
	float generalScore; //�����ɼ�

}SS;


/*---------------��������-------------------*/

//1.��ȡѧ����������
void readData(SS stu[], int N);
SS* readDataFromFile(int *N);

//2.����N��ѧ�������ܳɼ�
void calcuScore(SS stu[], int N);


//3.���������ɼ�����
void sortScore(SS stu[], int N);


//4.����һ���ĸ�ʽ���N��ѧ����������Ϣ
void printOut(SS stu[], int N);

#endif