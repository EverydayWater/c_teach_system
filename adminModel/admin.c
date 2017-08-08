#include "../publicModel/admin.h"
//#include "student.h"
//#include "teacher.h"
//#include "public.h"

int AdminChoice()//管理员查看学生信息方式
{
	int Admin = 0;
	printf("\n\t\t***************\n\n");
	printf("\t\t1,对自己信息修改\n");
	printf("\t\t2,对学生信息进行操作\n");
	printf("\t\t3,对教师信息进行操作\n");
	printf("\t\t0, 返回\n");
	printf("\n\t\t***************\n\n");
	
	printf("Input choice admin: ");
	scanf("%d", &Admin);
	while ('\n' != getchar())
	{}
	return Admin;
}
void AdminStu(StuHead *pStuHead,StuNode *pStuNode,TeaHead *pTeaHead,TeaNode *pTeaNode,Adm *pst)
{
	int  Choice = 0;
	while (1)
	{
		Choice = AdminChoice();
		switch (Choice)
		{
			case 1:
				system("clear");
				printf("\t\t\t\t***********修改登录密码***********\n\n");
				ModefyAdminSecret(pst);
				break;
			case 2:
				system("clear");
				printf("对学生信息进行操作:\n");
				Stuselect(pStuHead,pStuNode);//在test.c中	
				break;
			case 3:
				system("clear");
				printf("对教师信息进行操作:\n");
				TeaSelect(pTeaHead,pTeaNode);//在teacher_main.c中
				break;
			case 0:
				return;
			default:
				break;
		}
	}
}
Adm *CreatNewAdm()
{

	Adm *pst = (Adm *)malloc(sizeof(Adm));
	
	memset(pst,0,sizeof(Adm));
	return pst;

}
#if 0
void EntryAdmin(StuHead *pStuHead,StuNode *pStuNode,TeaHead *pTeaHead,TeaNode *pTeaNode)
{
	int num = 0;
	int i = 0;
	char name[] = "";
	
	do
	{
		printf("账户名： ");	
		gets(name);
		printf("请输入密码：");
		scanf("%d",&num);
		
		if((0 == strcmp("admin",name)) && (num == 123))
		{
			printf("\t\t\t登录成功\n\n");
			AdminStu(pStuHead,pStuNode,pTeaHead,pTeaNode);
			return;
		}
		else 
		{
			printf("帐号或者密码错误!\n请重新输入:\n");
			i++;
		}
		while('\n' != getchar())
		{}

	}while(i < 3);
	return;
}
#endif
void EntryAdmin(StuHead *pStuHead,StuNode *pStuNode,TeaHead *pTeaHead,TeaNode *pTeaNode,Adm *pst)
{

	int num = 0;
	int i = 0;
	char name[] = "";
	
	do
	{
		printf("账户名： ");	
		gets(name);
		printf("请输入密码：");
		scanf("%d",&num);
		
		if((0 == strcmp(pst->acAdmName,name)) && (num == pst->iAdmPass))
		{
			printf("\t\t\t登录成功\n\n");
			AdminStu(pStuHead,pStuNode,pTeaHead,pTeaNode,pst);
			return;
		}
		else 
		{
			printf("帐号或者密码错误!\n请重新输入:\n");
			i++;
		}
		while('\n' != getchar())
		{}

	}while(i < 3);
	return;
}
void ModefyAdminSecret(Adm *pst)
{
	char caName[NAME_LEN] = {'\0'};		
	printf("请输入新帐号：\n\n");
	getName(caName);
	strcpy(pst->acAdmName, caName);
	
	printf("\n");
	printf("请输入新密码：\n\n");
	pst->iAdmPass = getAdmPass();
	printf("\n");

}

int getAdmPass()
{
	int Pass = 0;
	
	while (1) 
	{
		
		if (scanf("%d", &Pass))
		{
			break;
		}
		else
		{
			printf("input error...\n");
			while ('\n' != getchar())
			{}
		}
	}

	return Pass;
}


