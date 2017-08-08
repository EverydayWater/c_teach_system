#ifndef TEACHER_H
#define TEACHER_H

#include "public.h"

#define TEACHER_PASSWD_LEN 20
#define TEACHER_NAME_LEN 20
#define NAME_LEN 20

typedef struct Teacher
{
	int iTeaId;
	char acTeaPasswd[TEACHER_PASSWD_LEN];
	char acTeaName[TEACHER_NAME_LEN];
	char cSex;
	//char acRex[3];

	struct Teacher *pNextNode;
}TeaNode;
typedef struct TeaHead
{
	int iTeaLen;
	
	TeaNode *pFirstNode;
}TeaHead;

TeaHead *CreatTeaEmptyList();
void InsertTeaNode(TeaHead *pTeaHead,TeaNode *pTeaNode);
void PrintfTeaList(TeaHead *pTeaHead);
TeaNode *CreatTeaNode();
void AddTeacher(TeaHead *pTeaHead,TeaNode *pTeaNode);//1,增一个教师
void FindTeacher(TeaHead *pTeaHead,TeaNode *pTeaNode);//2,查找一个教师
void ChangeTeacher(TeaHead *pTeaHead,TeaNode *pTeaNode);//3,改变一个教师信息
void DeleteTeacher(TeaHead *pTeaHead,TeaNode *pTeaNode);//4,删除一个教师
void changeTeaNodeInfo(TeaNode *pTeaNode);
TeaNode * findTeaNode(const TeaHead *pTeaHead, const char caName[NAME_LEN]);
void showTeaNodeInfo(const TeaNode *pTeaNode); 
int Lookchoice();
void LookTeaWay(TeaHead *pTeaHead,TeaNode *pTeaNode);//查看教师信息方式
int changeTeaChoice();
void getTeaName(char caName[NAME_LEN]);
int getTeaId();
char getTeaSex();
void deleteTeaNode(TeaHead *pTeaHead,char caName[NAME_LEN]);
int TeaFunctionSelect();
void TeaSelect();



#endif
