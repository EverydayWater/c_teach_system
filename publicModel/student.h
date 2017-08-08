#ifndef STUDENT_H
#define STUDENT_H

#include "public.h"

#define NAME_LEN 20
#define PASS_LEN 20
#define STUDENT_NAME_LEN 20
#define STUDENT_PASSWD_LEN 20
//#define STUDENT_BIRTHDAY_LEN 20

typedef struct Student
{
	int iStuId;
	char acStuName[STUDENT_NAME_LEN];
	char acStuPasswd[STUDENT_PASSWD_LEN];
	//char acStuBirthday[STUDENT_BIRTHDAY_LEN];
	int iStuAge;
	int iChineseScore;
	int iMathScore;
	int icLanguageScore;
	int iTotalScore;
	char cSex;
//	char acRex[3];
	
	struct Student *pNextNode;
}StuNode;
typedef struct StuHead
{
	int iStuLen;
	
	StuNode *pFirstNode;

}StuHead;

StuHead *CreatEmptyList();
void InsertNode(StuHead *pStuHead,StuNode *pStuNode);
void PrintfList(StuHead *pStuHead);
StuNode *CreatNode();
void AddStudent(StuHead *pStuHead,StuNode *pStuNode);//1,增一个学生
void FindStudent(StuHead *pStuHead,StuNode *pStuNode);//2,查找一个学生
void ChangeStu(StuHead *pStuHead,StuNode *pStuNode);//3,改变一个学生信息
void DeleteStu(StuHead *pStuHead,StuNode *pStuNode);//4,删除一个学生
void changeNodeInfo(StuNode *pStuNode);
StuNode * findNode(const StuHead *pStuHead, const char caName[NAME_LEN]);
void showNodeInfo(const StuNode *pStuNode); 
int Lookchoice();
void LookWay(StuHead *pStuHead,StuNode *pStuNode);//查看学生信息方式
int changeStuChoice();
void getName(char caName[NAME_LEN]);
int getAge();
char getSex();
void deleteNode(StuHead *pStuHead,char caName[NAME_LEN]);
int StuFunctionSelect();
void Stuselect(StuHead *pStuHead,StuNode *pStuNode);
StuNode * findNodeNum(const StuHead *pStuHead, const int num);
void FindStudentByNumber(StuHead *pStuHead,StuNode * pStuNode);
int getNewScore();
void changeChineseInfo(StuNode *pStuNode);
void ChangeStuByTeaChinese(StuHead *pStuHead,StuNode *pStuNode);
void ChangeStuByTeaMath(StuHead *pStuHead,StuNode *pStuNode);
void changeMathInfo(StuNode *pStuNode);
void ChangeStuByTeaProgram(StuHead *pStuHead,StuNode *pStuNode);
void changeProgramInfo(StuNode *pStuNode);
/*对学生成绩进行排序*/
//语文排序
int CompChineseScore(const void *p,const void *q);
void printStu(StuNode *Stu[],StuHead *pStuHead);
void sortStuChineseScore(StuHead *pStuHead);
//数学排序
int CompMathScore(const void *p,const void *q);
void sortStuMathScore(StuHead *pStuHead);
//编程排序
int CompProgramScore(const void *p,const void *q);
void sortStuProgramScore(StuHead *pStuHead);
//总成绩排序
int CompTotalScore(const void *p,const void *q);
void sortStuTotalScore(StuHead *pStuHead);




#endif
