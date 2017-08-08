#include "../publicModel/main.h"
#include "../publicModel/admin.h"
//#include "public.h"
//#include "student.h"
//#include "teacher.h"
#include "../publicModel/student_self.h"
#include "../publicModel/teacher_self.h"

int mainchangeChoice()
{
	int iChoice = 0;
				
		printf("\t\t\t*******************************************\n");
     	printf("\t\t\t*******************************************\n");
     	printf("\t\t\t****************1,管理员登录***************\n");
     	printf("\t\t\t****************2,学生登录*****************\n");
     	printf("\t\t\t****************3,教师登录*****************\n");
     	printf("\t\t\t****************0,退出*********************\n");
     	printf("\t\t\t*******************************************\n");
    	printf("\t\t\t*******************************************\n\n");

	printf("Input choice: ");
	scanf("%d", &iChoice);
	while ('\n' != getchar())
	{}
	return iChoice;
}
void LoginSystem(StuHead *pStuHead,StuNode *pStuNode,TeaHead *pTeaHead,TeaNode *pTeaNode,Adm *pst) //在mainControl.c 文件中
{
	int iChoice = 0;
	while (1)
	{
		iChoice = mainchangeChoice();
	
		switch (iChoice)
		{
			case 1:
				system("clear");
				printf("\n\t\t\t欢迎管理员登录！\n");
				EntryAdmin(pStuHead,pStuNode,pTeaHead,pTeaNode,pst);//admin.h管理员登录//在admin.c文件中
				break;
			case 2:
				system("clear");
				printf("\n\t\t\t欢迎学生登录！\n");
				EntryStudentSelf(pStuHead,pStuNode);
				break;
			case 3:
				system("clear");
				printf("\n\t\t\t欢迎教师登录！\n");
				EntryTeacherSelf(pStuHead,pStuNode,pTeaHead,pTeaNode);//teacher_self.h教师登录//在teacher_self.c文件中
				break;
			case 0:
				system("clear");
				printf("\n\t\t\t退出系统！\n\n\n\n");
				return ;
			default:
			break;
		}
	}

}
void SaveTeaFile(TeaHead *pTeaHead)
{
	FILE *fp;
	
	TeaNode *pTeaNode = pTeaHead->pFirstNode;

	fp = fopen("Teacher.txt","w");
	if(NULL == fp)
	{
		printf("Open file failed!\n");
		return ;	
	}
	while(pTeaNode != NULL)
	{
		fprintf(fp,"%d %s %s %c",pTeaNode->iTeaId,pTeaNode->acTeaPasswd,pTeaNode->acTeaName,pTeaNode->cSex);
		pTeaNode = pTeaNode->pNextNode;
	}
	fclose(fp);
}
void ReadTeaFile(TeaHead *pTeaHead)
{
	TeaNode *pTeaNode;
	FILE *fp;
	fp = fopen("Teacher.txt","r");
	if(NULL == fp)
	{
		printf("Open file failed!\n");
		return ;
	}
	while(!feof(fp))
	{
		pTeaNode = (TeaNode *)malloc(sizeof(TeaNode));
			
		fscanf(fp,"%d %s %s %c",&pTeaNode->iTeaId,pTeaNode->acTeaPasswd,pTeaNode->acTeaName,&pTeaNode->cSex);
		if(feof(fp))
		{
			break;
		}
		pTeaNode->pNextNode = NULL;
		InsertTeaNode(pTeaHead,pTeaNode);
	}
	
	fclose(fp);
	
}
#if 0 
void SaveStuFile(StuHead *pStuHead)
{
	FILE *fp;
	
	StuNode *pStuNode = pStuHead->pFirstNode;

	fp = fopen("Stuent.txt","w");
	if(NULL == fp)
	{
		printf("Open file failed!\n");
		return ;	
	}
	while(pStuNode != NULL)
	{
		fprintf(fp,"%d %s %s %c %d %d %d %d",pStuNode->iStuId,
		pStuNode->acStuPasswd,pStuNode->acStuName,pStuNode->cSex,
		pStuNode->iStuAge,pStuNode->iChineseScore,pStuNode->iMathScore,
		pStuNode->icLanguageScore);   //,pStuNode->iTotalScore);
	
		pStuNode = pStuNode->pNextNode;
	}

	fclose(fp);
}	

void ReadStuFile(StuHead *pStuHead)
{

	StuNode *pStuNode;
	FILE *fp;
	fp = fopen("Student.txt","r");
	if(NULL == fp)
	{
		printf("Open file failed!\n");
		return ;
	}
	while(!feof(fp))
	{
		pStuNode = (StuNode *)malloc(sizeof(StuNode));

		fscanf(fp,"%d %s %s %c %d %d %d %d",&pStuNode->iStuId,
		pStuNode->acStuPasswd,pStuNode->acStuName,&pStuNode->cSex,
		&pStuNode->iStuAge,&pStuNode->iChineseScore,&pStuNode->iMathScore,
		&pStuNode->icLanguageScore);                //&pStuNode->iTotalScore);

		if(feof(fp))
		{
			break;
		}
		pStuNode->pNextNode = NULL;
		InsertNode(pStuHead,pStuNode);
	}
}
#endif
void SaveStuFile(StuHead *pStuHead)
{
	StuNode *pStuNode =NULL;
	FILE *sfp = NULL;
	pStuNode = pStuHead->pFirstNode;

	sfp = fopen("Student.txt","wb");
	if(NULL == sfp)
	{
		printf("sfp open filed\n");
		return ;
	}
	while(NULL != pStuNode)
	{
		fwrite(pStuNode,sizeof(StuNode),1,sfp);
		pStuNode = pStuNode->pNextNode;
	}
	fclose(sfp);
}
void ReadStuFile(StuHead *pStuHead)
{
	StuNode *pStuNode = NULL;
	FILE *sfp = NULL;

	sfp = fopen("Student.txt","rb");
	if(NULL == sfp)
	{
		printf("sfp open filed\n");
		return;
	}
	while(!feof(sfp))
	{
		pStuNode = (StuNode *)malloc(sizeof(StuNode));
		fread(pStuNode,sizeof(StuNode),1,sfp);
	    if(feof(sfp))
		{
			break;
		}
		pStuNode->pNextNode = NULL;
		InsertNode(pStuHead,pStuNode);
	}
	fclose(sfp);
}
void SaveAdmFile(Adm *pst)
{
	FILE *afp = NULL;

	afp = fopen("Admin.txt","w");
	if(NULL == afp)
	{
		printf("afp open filed\n");
		return ;
	}
		
		fprintf(afp,"%s %d",pst->acAdmName,pst->iAdmPass);

	fclose(afp);
}
void ReadAdmFile(Adm *pst)
{

	FILE *afp = NULL;
	
	afp = fopen("Admin.txt","r");
	if(NULL == afp)
	{
		printf("afp open filed\n");
		return;
	}
	
	while(!feof(afp))
	{
		fscanf(afp,"%s %d",pst->acAdmName,&pst->iAdmPass);
		if(feof(afp))
		{
			break;
		}
	}

	fclose(afp);
}

/********************************************************/
/*********************销毁链表***************************/
/********************************************************/
void destroyStu(StuHead *pStuHead,StuNode *pStuNode)
{
	if(NULL == pStuHead || NULL == pStuNode)
	{
		return;
	}
	StuNode *pStuNodeTmp = pStuHead->pFirstNode;
	while(NULL != pStuNodeTmp)
	{
		StuNode *pStuNode = pStuNodeTmp;
		pStuNodeTmp = pStuNodeTmp->pNextNode;
		free(pStuNode);
		pStuNode = NULL;		
	}
}
void destroyTea(TeaHead *pTeaHead,TeaNode *pTeaNode)
{
	if(NULL == pTeaHead || NULL == pTeaNode)
	{
		return;
	}
	TeaNode *pTeaNodeTmp = pTeaHead->pFirstNode;
	while(NULL != pTeaNodeTmp)
	{
		TeaNode *pTeaNode = pTeaNodeTmp;
		pTeaNodeTmp = pTeaNodeTmp->pNextNode;
		free(pTeaNode);
		pTeaNode = NULL;		
	}
}
void destroyAdm(Adm *pst)
{
	pst = CreatNewAdm();
	
	free(pst);
	pst = NULL;
}
