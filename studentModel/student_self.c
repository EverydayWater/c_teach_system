#include "../publicModel/student_self.h"
//#include "student.h"
//#include "public.h"

int StuSelfInfor()
{
	int SeekStuSelf = 0;
	
	printf("\n\t\t***************\n\n");
	printf("\t\t1,修改密码\n");
	printf("\t\t2,修改姓名\n");
	printf("\t\t3,修改年龄\n");
	printf("\t\t4,显示学生自己全部信息\n");
	printf("\t\t0, 返回\n");
	printf("\n\t\t***************\n\n");
	
	printf("Input choice SeekStuSelf: ");
	scanf("%d", &SeekStuSelf);
	while ('\n' != getchar())
	{}
	return SeekStuSelf;

} 
void StuSelfSelect(StuNode *pStuNode)
{	
	char name[NAME_LEN] = {'\0'};	
	int select = 0;
	while (1)
	{
		select = StuSelfInfor();
		switch (select)
		{
			case 1:
				system("clear");
				printf("修改密码\n");	
				ModefyStuSecret(pStuNode);
				break;
			case 2:
				system("clear");
				printf("修改姓名\n");
			  	getName(name);
				strcpy(pStuNode->acStuName,name);
				break;
			case 3:
				system("clear");
				printf("修改年龄\n");
				pStuNode->iStuAge = getAge();	
				break;
			case 4:
				system("clear");
				printf("显示学生自己全部信息\n");	
				showNodeInfo(pStuNode);
				break;
			case 0:
				return;
			default:
				break;
		}
	}
}
	
void EntryStudentSelf(StuHead *pStuHead,StuNode *pStuNode)
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
	
		StuNode *pStuNode = NULL;
		pStuNode = findNode(pStuHead,name);
	
		if(NULL != pStuNode && (0 == strcmp(pStuNode->acStuPasswd,pass)))
		{
			printf("\t\t\t登录成功\n\n");
			StuSelfSelect(pStuNode);//在文件student_self.c中
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

void ModefyStuSecret(StuNode *pStuNode)
{
	char caName[NAME_LEN] = {'\0'};		
	printf("请输入新帐号：\n\n");
	getName(caName);
	strcpy(pStuNode->acStuName, caName);
	
	printf("\n");
	printf("请输入新密码：\n\n");
	getName(caName);
	strcpy(pStuNode->acStuPasswd, caName);
	printf("\n");

}







