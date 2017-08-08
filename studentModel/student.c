#include "../publicModel/student.h"

StuHead *CreatEmptyList()
{
	StuHead *pStuHead = (StuHead *)malloc(sizeof(StuHead));
	
	pStuHead->iStuLen = 0;
	pStuHead->pFirstNode = NULL;

	return pStuHead;
}
void InsertNode(StuHead *pStuHead,StuNode *pStuNode)
{
	if(NULL == pStuHead || NULL == pStuNode)
	{
		return;
	}
	StuNode *pStuNodeTmp = pStuHead->pFirstNode;
	if(NULL != pStuNodeTmp)
	{
		while (NULL != pStuNodeTmp->pNextNode)
		{
			pStuNodeTmp = pStuNodeTmp->pNextNode;
		}
		pStuNodeTmp->pNextNode = pStuNode;
	}
	else
	{
		pStuHead->pFirstNode = pStuNode;
	}
	pStuHead->iStuLen++;
}
void PrintfList(StuHead *pStuHead)
{
	StuNode *pStuNode = pStuHead->pFirstNode;
	printf("\t学号\t密码\t姓名\t性别\t年龄\t语文\t数学\t编程\t总成绩\t\n");
	while (NULL != pStuNode)
	{
		printf(" \t%d\t%s\t%s\t%c\t%d\t%d\t%d\t%d\t%d\t\n",pStuNode->iStuId,
		pStuNode->acStuPasswd,pStuNode->acStuName,pStuNode->cSex,
		pStuNode->iStuAge,pStuNode->iChineseScore,pStuNode->iMathScore,
		pStuNode->icLanguageScore,pStuNode->iTotalScore);

		pStuNode = pStuNode->pNextNode;
	}
	printf("\n\n\t\t\t\t*****************\n");
	printf("\t\t\t\t学生总数为 : %d",pStuHead->iStuLen);
	printf("\n\t\t\t\t*****************\n");
	
}
StuNode *CreatNode()
{
	StuNode *pStuNode = (StuNode *)malloc(sizeof(StuNode));                                            
	printf("Input information (Id,Name,passwd,age,chscore,mascore,clscore,total,Sex):\n");
	
	printf("please input Id: ");
	scanf("%d",&pStuNode->iStuId);
	printf("please input name: ");
	scanf("%s",pStuNode->acStuName);
	printf("please input passwd: ");
	getchar();
	scanf("%s",pStuNode->acStuPasswd);
	printf("please input age: ");
	scanf("%d",&pStuNode->iStuAge);
	printf("please input chinesescore: ");
	scanf("%d",&pStuNode->iChineseScore);
	printf("please input mathscore: ");
	scanf("%d",&pStuNode->iMathScore);
	printf("please input clanguagescore: ");
	scanf("%d",&pStuNode->icLanguageScore);
	printf("please input sex: ");
	getchar();
	pStuNode->cSex = getchar();
	
	pStuNode->iTotalScore = pStuNode->iMathScore + pStuNode->iChineseScore + pStuNode->icLanguageScore;
	pStuNode->pNextNode = NULL;
	return pStuNode;
}
StuNode * findNode(const StuHead *pStuHead, const char caName[NAME_LEN])
//按学生姓名查找学生
{
	if (NULL == pStuHead || NULL == caName)
	{
		return NULL;
	}
	if (0 == strlen(caName))
	{
		return NULL;
	}

	StuNode *pStuNode = NULL;
	pStuNode = pStuHead->pFirstNode;
	while (NULL != pStuNode)
	{
		if (0 == strcmp(caName, pStuNode->acStuName))
		{
			break;
		}
		pStuNode = pStuNode->pNextNode;
	}

	return pStuNode;
}
StuNode * findNodeNum(const StuHead *pStuHead, const int num)
//按学生学号遍历学生节点，有学生则返回该节点  
{
	if (NULL == pStuHead)
	{
		return NULL;
	}

	StuNode *pStuNode = NULL;
	pStuNode = pStuHead->pFirstNode;
	while (NULL != pStuNode)
	{
		if (num == pStuNode->iStuId)
		{
			break;
		}
		pStuNode = pStuNode->pNextNode;
	}

	return pStuNode;
}
void FindStudentByNumber(StuHead *pStuHead,StuNode *pStuNode)
//教师功能：按照学号查找学生
{
	char cCon = '\0';
	int num = 0;
	do
	{
		printf("please input number to find: ");
		scanf("%d",&num);
		pStuNode = findNodeNum(pStuHead, num);
		if (NULL != pStuNode)
		{
			showNodeInfo(pStuNode);
		}
		else
		{
			printf("%d is not existed...\n", num);
		}
		
		while ('\n' != getchar())
		{}
		printf("Continue find people ? Y/N: ");
		cCon = getchar();
		getchar();
	}while('Y' == cCon || 'y' == cCon);
	
	printf("\n\n");
}
void ChangeStuByTeaChinese(StuHead *pStuHead,StuNode *pStuNode)
//教师改变学生语文成绩
{
	char cCon = '\0';	
	char caName[NAME_LEN] = {'\0'};
	
	do
	{
		printf("please input name to find to change: ");
		scanf("%s", caName);
		pStuNode = findNode(pStuHead, caName);
		if (NULL != pStuNode)
		{
			showNodeInfo(pStuNode);
			changeChineseInfo(pStuNode);
		}
		else
		{
			printf("%s is not existed...\n", caName);
		}
	
		while ('\n' != getchar())
		{}
		printf("Continue change people score? Y/N: ");
		cCon = getchar();
		getchar();
	}while('Y' == cCon || 'y' == cCon);

	printf("\n\n");

}
void changeChineseInfo(StuNode *pStuNode)
{
	if (NULL == pStuNode)
	{
		return;
	}
	pStuNode->iChineseScore = getNewScore();
	showNodeInfo(pStuNode);
}
int getNewScore()
{
	int iScore = 0;
	printf("\n\n**************\n");
	while (1) 
	{
		printf("please input new score: ");
		if (scanf("%d", &iScore))
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

	return iScore;
}
void ChangeStuByTeaMath(StuHead *pStuHead,StuNode *pStuNode)
//教师改变学生数学成绩
{
	char cCon = '\0';	
	char caName[NAME_LEN] = {'\0'};
	
	do
	{
		printf("please input name to find to change: ");
		scanf("%s", caName);
		pStuNode = findNode(pStuHead, caName);
		if (NULL != pStuNode)
		{
			showNodeInfo(pStuNode);
			changeMathInfo(pStuNode);
		}
		else
		{
			printf("%s is not existed...\n", caName);
		}
	
		while ('\n' != getchar())
		{}
		printf("Continue change people score? Y/N: ");
		cCon = getchar();
		getchar();
	}while('Y' == cCon || 'y' == cCon);

	printf("\n\n");

}
void changeMathInfo(StuNode *pStuNode)
{
	if (NULL == pStuNode)
	{
		return;
	}
	pStuNode->iMathScore = getNewScore();
	showNodeInfo(pStuNode);
}

void ChangeStuByTeaProgram(StuHead *pStuHead,StuNode *pStuNode)
//教师改变学生编程成绩
{
	char cCon = '\0';	
	char caName[NAME_LEN] = {'\0'};
	
	do
	{
		printf("please input name to find to change: ");
		scanf("%s", caName);
		pStuNode = findNode(pStuHead, caName);
		if (NULL != pStuNode)
		{
			showNodeInfo(pStuNode);
			changeProgramInfo(pStuNode);
		}
		else
		{
			printf("%s is not existed...\n", caName);
		}
	
		while ('\n' != getchar())
		{}
		printf("Continue change people score? Y/N: ");
		cCon = getchar();
		getchar();
	}while('Y' == cCon || 'y' == cCon);

	printf("\n\n");

}
void changeProgramInfo(StuNode *pStuNode)
{
	if (NULL == pStuNode)
	{
		return;
	}
	pStuNode->icLanguageScore = getNewScore();
	showNodeInfo(pStuNode);
}

void showNodeInfo(const StuNode *pStuNode)//显示当前节点信息
{
	if (NULL == pStuNode)
	{
		return;
	}

	printf("\n\n\t******************************NodeInfo*********************************\n");

	printf("\t学号\t密码\t姓名\t性别\t年龄\t语文\t数学\t编程\t总成绩\t\n");
	printf(" \t%d\t%s\t%s\t%c\t%d\t%d\t%d\t%d\t%d\t\n",pStuNode->iStuId,
		pStuNode->acStuPasswd,pStuNode->acStuName,pStuNode->cSex,
		pStuNode->iStuAge,pStuNode->iChineseScore,pStuNode->iMathScore,
		pStuNode->icLanguageScore,pStuNode->iTotalScore);
	
	printf("\t******************************NodeInfo*********************************\n");
}
void AddStudent(StuHead *pStuHead,StuNode *pStuNode)
//1，添加学生
{

	char cCon = '\0';
	do
	{	pStuNode = CreatNode(pStuNode);
		 InsertNode(pStuHead,pStuNode);
	
		while('\n' != getchar())
		{
		}
		printf("Continue add people ?Y/N:");
		
		cCon = getchar();
		getchar();

	}while('Y' == cCon || 'y' == cCon);

//	PrintfList(pStuHead);
	printf("\n\n");
}
void FindStudent(StuHead *pStuHead,StuNode *pStuNode)
//2，查找学生
{
	char cCon = '\0';
	char caName[NAME_LEN] = {'\0'};
	do
	{
		printf("please input name to find: ");
		scanf("%s", caName);
		pStuNode = findNode(pStuHead, caName);
		if (NULL != pStuNode)
		{
			showNodeInfo(pStuNode);
		}
		else
		{
			printf("%s is not existed...\n", caName);
		}
		
		while ('\n' != getchar())
		{}
		printf("Continue find people ? Y/N: ");
		cCon = getchar();
		getchar();
	}while('Y' == cCon || 'y' == cCon);
	
	printf("\n\n");
}
void ChangeStu(StuHead *pStuHead,StuNode *pStuNode)
//3，改变学生信息
{
	char cCon = '\0';
	char caName[NAME_LEN] = {'\0'};
	
	do
	{
		printf("please input name to find to change: ");
		scanf("%s", caName);
		pStuNode = findNode(pStuHead, caName);
		if (NULL != pStuNode)
		{
			showNodeInfo(pStuNode);
			changeNodeInfo(pStuNode);
		}
		else
		{
			printf("%s is not existed...\n", caName);
		}
	
		//while ('\n' != getchar())
		//{}
		printf("Continue change people ? Y/N: ");
		cCon = getchar();
		getchar();
	}while('Y' == cCon || 'y' == cCon);

	printf("\n\n");


}
void DeleteStu(StuHead *pStuHead,StuNode *pStuNode)
//4,删除学生
{
	
	char cCon = '\0';
	char caName[NAME_LEN] = {'\0'};
	do
	{
		printf("please input name to delete: ");
		scanf("%s", caName);
	
		deleteNode(pStuHead, caName);
		PrintfList(pStuHead);
		
		while ('\n' != getchar())
		{}
		printf("Continue find people ? Y/N: ");
		cCon = getchar();
		getchar();
	}while('Y' == cCon || 'y' == cCon);
	
}
int Lookchoice()//管理员查看学生信息方式
{
	int look = 0;
	printf("\n\t\t***************\n\n");
	printf("\t\t1,按姓名查找\n");
	printf("\t\t2,查看所有学生信息\n");
	printf("\t\t0, 返回\n");
	printf("\n\t\t***************\n\n");
	
	printf("Input choice look: ");
	scanf("%d", &look);
	while ('\n' != getchar())
	{}
	return look;
}
void LookWay(StuHead *pStuHead,StuNode *pStuNode)//管理员查看学生信息
{
	int icho = 0;
	while(1)
	{
		icho = Lookchoice();
		switch(icho)
		{
			case 1:
				FindStudent(pStuHead,pStuNode);
				break;
			case 2:
				PrintfList(pStuHead);
				break;
			case 0:
				return;
				break;
			default:
			break;

		}

	}

}
int changeStuChoice()
{
	int iChoice = 0;
	printf("\n\n***************\n");
	printf("1, 修改名字\n");
	printf("2, 修改年龄\n");
	printf("3, 修改性别\n");
	printf("0, 返回\n");
	printf("Input choice: ");
	scanf("%d", &iChoice);
	while ('\n' != getchar())
	{}

	return iChoice;
}
void getName(char caName[NAME_LEN])
{
	if (NULL == caName)
	{
		return;
	}

	memset(caName, '\0', NAME_LEN);
	fgets(caName, NAME_LEN, stdin);
	
	if ('\n' == caName[NAME_LEN - 1])
	{
		caName[NAME_LEN - 1] = '\0';
	}
	else if ('\0' == caName[NAME_LEN - 1] 
			 && ('\n' == caName[NAME_LEN - 2] 
			    || '\0' == caName[NAME_LEN - 2]))
	{
		int iLen = strlen(caName);
		caName[iLen - 1] = '\0';
	}
	else
	{
		caName[NAME_LEN - 1] = '\0';
		while ('\n' != getchar())
		{}
	}
}

int getAge()
{
	int iAge = 0;
	printf("\n\n**************\n");
	while (1) 
	{
		printf("please input new age: ");
		if (scanf("%d", &iAge))
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

	return iAge;
}

char getSex()
{
	char cSex = '\0';
	printf("\n\n**************\n");
	while (1)
	{
		printf("please input new sex: ");
		cSex = getchar();
		if ('f' == cSex || 'm' == cSex)
		{
			break;
		}
		else if ('\n' == cSex)
		{
		}
		else
		{
			while ('\n' != getchar())
			{}
		}
	}

	return cSex;
}
void changeNodeInfo(StuNode *pStuNode)
{
	if (NULL == pStuNode)
	{
		return;
	}

	char caName[NAME_LEN] = {'\0'};
	int iChoice = 0;
	while (1)
	{
		iChoice = changeStuChoice();
		switch (iChoice)
		{
			case 1:
				getName(caName);
				strcpy(pStuNode->acStuName, caName);
				break;
			case 2:
				pStuNode->iStuAge = getAge();
				break;
			case 3:
				pStuNode->cSex = getSex();
				break;
			case 0:
				return;
			default:
				break;
		}
		showNodeInfo(pStuNode);
	}
}
void deleteNode(StuHead *pStuHead, char caName[NAME_LEN])
{
	if (NULL == pStuHead || NULL == caName)
	{
		return;
	}
	if (0 == strlen(caName))
	{
		return;
	}

	StuNode *pStuNodeCur = NULL;
	StuNode *pStuNodePre = NULL;

	pStuNodeCur = pStuHead->pFirstNode;
	pStuNodePre = pStuNodeCur;

	while (NULL != pStuNodeCur)
	{
		if (0 == strcmp(caName, pStuNodeCur->acStuName))
		{
			break;
		}
		pStuNodePre = pStuNodeCur;
		pStuNodeCur = pStuNodeCur->pNextNode;
	}

	if (NULL != pStuNodeCur)
	{
		if (pStuNodeCur == pStuNodePre)    //第一个节点匹配
		{
			pStuHead->pFirstNode = pStuNodeCur->pNextNode;
		}
		else if (NULL == pStuNodeCur->pNextNode)    //最后一个节点匹配
		{
			pStuNodePre->pNextNode = NULL;
		}
		else    //中间某个节点匹配
		{
			pStuNodePre->pNextNode = pStuNodeCur->pNextNode;
		}

		free(pStuNodeCur);
		pStuNodeCur = NULL;
		pStuHead->iStuLen--;
	}
}


/**************************************************/
/*教师分别对学生的语文、数学、编程、总成绩进行排序*/
/**************************************************/

//对语文成绩排序
int CompChineseScore(const void *p,const void *q)
 {
     if(((StuNode *)*(int *)p)->iChineseScore < ((StuNode *)*(int *)q)->iChineseScore)
     {
        return 1;
     }     
	return 0;
 }
 void sortStuChineseScore(StuHead *pStuHead)
 {
     StuNode *pStuNode = pStuHead->pFirstNode;
     int i = 0;
     StuNode *Stu[pStuHead->iStuLen];
 
     while(NULL != pStuNode)
     {
         Stu[i] = pStuNode;
         pStuNode = pStuNode->pNextNode;
         i++;
     }   
     
     qsort(Stu,i,sizeof(StuNode *),CompChineseScore);
     
     printStu(Stu,pStuHead);
 }

void printStu(StuNode *Stu[],StuHead *pStuHead)
{
    int i = 0;

	printf("\t学号\t密码\t姓名\t性别\t年龄\t语文\t数学\t编程\t总成绩\t\n");
    for(i = 0;i < pStuHead->iStuLen;i++)
	{
		printf(" \t%d\t%s\t%s\t%c\t%d\t%d\t%d\t%d\t%d\t\n",Stu[i]->iStuId,
		Stu[i]->acStuPasswd,Stu[i]->acStuName,Stu[i]->cSex,
		Stu[i]->iStuAge,Stu[i]->iChineseScore,Stu[i]->iMathScore,
		Stu[i]->icLanguageScore,Stu[i]->iTotalScore);
	
	}
}

//对数学成绩排序
int CompMathScore(const void *p,const void *q)
 {
     if(((StuNode *)*(int *)p)->iMathScore < ((StuNode *)*(int *)q)->iMathScore)
     {
        return 1;
     }     
	return 0;
 }
 void sortStuMathScore(StuHead *pStuHead)
 {
     StuNode *pStuNode = pStuHead->pFirstNode;
     int i = 0;
     StuNode *Stu[pStuHead->iStuLen];
 
     while(NULL != pStuNode)
     {
         Stu[i] = pStuNode;
         pStuNode = pStuNode->pNextNode;
         i++;
     }   
     
     qsort(Stu,i,sizeof(StuNode *),CompMathScore);
     
     printStu(Stu,pStuHead);
 }

//对编程成绩排序

int CompProgramScore(const void *p,const void *q)
 {
     if(((StuNode *)*(int *)p)->icLanguageScore < ((StuNode *)*(int *)q)->icLanguageScore)
     {
        return 1;
     }     
	return 0;
 }
 void sortStuProgramScore(StuHead *pStuHead)
 {
     StuNode *pStuNode = pStuHead->pFirstNode;
     int i = 0;
     StuNode *Stu[pStuHead->iStuLen];
 
     while(NULL != pStuNode)
     {
         Stu[i] = pStuNode;
         pStuNode = pStuNode->pNextNode;
         i++;
     }   
     
     qsort(Stu,i,sizeof(StuNode *),CompProgramScore);
     
     printStu(Stu,pStuHead);
 }


//对总成绩排序
int CompTotalScore(const void *p,const void *q)
 {
     if(((StuNode *)*(int *)p)->iTotalScore < ((StuNode *)*(int *)q)->iTotalScore)
     {
        return 1;
     }     
	return 0;
 }
 void sortStuTotalScore(StuHead *pStuHead)
 {
     StuNode *pStuNode = pStuHead->pFirstNode;
     int i = 0;
     StuNode *Stu[pStuHead->iStuLen];
 
     while(NULL != pStuNode)
     {
         Stu[i] = pStuNode;
         pStuNode = pStuNode->pNextNode;
         i++;
     }   
     
     qsort(Stu,i,sizeof(StuNode *),CompTotalScore);
     
     printStu(Stu,pStuHead);
 }


