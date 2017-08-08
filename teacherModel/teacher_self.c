#include "../publicModel/teacher_self.h"

int TeaSelfInfor()
{
	int SeekTeaSelf = 0;
	
	printf("\n\t\t***************\n\n");
	printf("\t\t1,修改密码\n");
	printf("\t\t2,修改姓名\n");
	printf("\t\t3,显示本人信息\n");
	printf("\t\t4,按名字查找学生\n");
	printf("\t\t5,按学号查找学生\n");
	printf("\t\t6,修改学生成绩\n");
	printf("\t\t7,对学生成绩进行排序\n");
	printf("\t\t0, 返回\n");
	printf("\n\t\t***************\n\n");
	
	printf("Input choice SeekTeaSelf: ");
	scanf("%d", &SeekTeaSelf);
	while ('\n' != getchar())
	{}

	return SeekTeaSelf;
}

void TeaSelfSelect(StuHead *pStuHead,StuNode *pStuNode,TeaNode *pTeaNode)
{	
	char name[NAME_LEN] = {'\0'};
	int select = 0;
	while (1)
	{
		select = TeaSelfInfor();
		switch (select)
		{
			case 1:
				system("clear");	
				printf("修改密码\n");	
				ModefyTeaSecret(pTeaNode);
				break;
			case 2:
				system("clear");
				printf("修改姓名\n");
				getName(name);
				strcpy(pTeaNode->acTeaName,name);
				break;
			case 3:
				system("clear");
				printf("显示本人信息\n");
			showTeaNodeInfo(pTeaNode);	
				break;
			case 4:
				system("clear");
				printf("按名字查找学生\n");
				FindStudent(pStuHead,pStuNode);		
				break;
			case 5:
				system("clear");
				printf("按学号查找学生\n");	
				FindStudentByNumber(pStuHead,pStuNode);
				break;
			case 6:
				system("clear");
				printf("修改学生成绩\n");	
				changeStuGread(pStuHead,pStuNode);
				break;
			case 7:
				system("clear");
				printf("对学生成绩进行排序\n");	
				qSortStuGread(pStuHead,pStuNode);
				break;
			case 0:
				return;
			default:
				break;
		}
	}
}

void EntryTeacherSelf(StuHead *pStuHead,StuNode *pStuNode,TeaHead *pTeaHead,TeaNode *pTeaNode)
{
	int i = 0;
	char name[NAME_LEN] = "";
	char pass[PASS_LEN] = "";

	do
	{
		printf("账户名： ");	
		gets(name);
		printf("请输入密码：");
		getName(pass);		

		TeaNode *pTeaNode = NULL;
		pTeaNode = findTeaNode(pTeaHead,name);
	
		if(NULL != pTeaNode && (0 == strcmp(pTeaNode->acTeaPasswd,pass)))
		{
			printf("\t\t\t登录成功\n\n");
			TeaSelfSelect(pStuHead,pStuNode,pTeaNode);//在文件teacher_self.c中
			return;
		}
		else 
		{
			printf("帐号或者密码错误!\n请重新输入:\n");
			i++;
		}
	//	while('\n' != getchar())
	//	{}

	}while(i < 3);
	return;
}
void changeStuGread(StuHead *pStuHead,StuNode *pStuNode)
{
	int select = 0;
	
	while(1)
	{
		select = StuGradeChange();
		switch (select)		
		{
			case 1:
				printf("\t请对语文成绩修改\n\n");
				ChangeStuByTeaChinese(pStuHead,pStuNode);
				break;
			case 2:
				printf("\t请对数学成绩修改\n\n");
				ChangeStuByTeaMath(pStuHead,pStuNode);
				break;
			case 3:
				printf("\t请对编程成绩修改\n\n");
				ChangeStuByTeaProgram(pStuHead,pStuNode);
				break;
			case 0:
				return;
			default:
				break;
		}

	}
}
int StuGradeChange()
{
	
	int Select = 0;
	
	printf("\n\t\t***************\n\n");
	printf("\t\t1,修改语文成绩\n");
	printf("\t\t2,修改数学成绩\n");
	printf("\t\t3,修改编程成绩\n");
	printf("\t\t0, 返回\n");
	printf("\n\t\t***************\n\n");
	
	printf("Input choice Select: ");
	scanf("%d", &Select);
	while ('\n' != getchar())
	{}

	return Select;
}
void qSortStuGread(StuHead *pStuHead,StuNode *pStuNode)
{
	int select = 0;
	
	while(1)
	{
		select = StuGradeSort();
		switch (select)		
		{
			case 1:
				printf("\t对语文成绩排序\n\n");
				sortStuChineseScore(pStuHead);
				break;
			case 2:
				printf("\t对数学成绩排序\n\n");
				sortStuMathScore(pStuHead);				
				break;
			case 3:
				printf("\t对编程成绩排序\n\n");
				sortStuProgramScore(pStuHead);
				break;
			case 4:
				printf("\t对总成绩排序\n\n");
				sortStuTotalScore(pStuHead);
				break;
			case 0:
				return;
			default:
				break;
		}

	}
}
int StuGradeSort()
{
	
	int Select = 0;
	
	printf("\n\t\t***************\n\n");
	printf("\t\t1,对语文成绩进行排序\n");
	printf("\t\t2,对数学成绩进行排序\n");
	printf("\t\t3,对编程成绩进行排序\n");
	printf("\t\t4,对总成绩排序\n");
	printf("\t\t0, 返回\n");
	printf("\n\t\t***************\n\n");
	
	printf("Input choice Select: ");
	scanf("%d", &Select);
	while ('\n' != getchar())
	{}
	return Select;
}

void ModefyTeaSecret(TeaNode *pTeaNode)
{
	char caName[NAME_LEN] = {'\0'};		
	printf("请输入新帐号：\n\n");
	getName(caName);
	strcpy(pTeaNode->acTeaName, caName);
	
	printf("\n");
	printf("请输入新密码：\n\n");
	getName(caName);
	strcpy(pTeaNode->acTeaPasswd, caName);
	printf("\n");

}
