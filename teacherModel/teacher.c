#include "../publicModel/teacher.h"

TeaHead *CreatTeaEmptyList()
{
	TeaHead *pTeaHead = (TeaHead *)malloc(sizeof(TeaHead));
	
	pTeaHead->iTeaLen = 0;
	pTeaHead->pFirstNode = NULL;

	return pTeaHead;
}
void InsertTeaNode(TeaHead *pTeaHead,TeaNode *pTeaNode)
{
	if(NULL == pTeaHead || NULL == pTeaNode)
	{
		return;
	}
	TeaNode *pTeaNodeTmp = pTeaHead->pFirstNode;
	if(NULL != pTeaNodeTmp)
	{
		while (NULL != pTeaNodeTmp->pNextNode)
		{
			pTeaNodeTmp = pTeaNodeTmp->pNextNode;
		}
		pTeaNodeTmp->pNextNode = pTeaNode;
	}
	else
	{
		pTeaHead->pFirstNode = pTeaNode;
	}
	pTeaHead->iTeaLen++;
}
void PrintfTeaList(TeaHead *pTeaHead)
{
	TeaNode *pTeaNode = pTeaHead->pFirstNode;
	printf("\t教职号\t密码\t姓名\t性别\t\n");
	while (NULL != pTeaNode)
	{
		printf(" \t%d\t%s\t%s\t%c\t\n",pTeaNode->iTeaId,
		pTeaNode->acTeaPasswd,pTeaNode->acTeaName,pTeaNode->cSex);

		pTeaNode = pTeaNode->pNextNode;
	}
	printf("\n\n\t\t\t\t*****************\n");
	printf("\t\t\t\t教师总数为 : %d",pTeaHead->iTeaLen);
	printf("\n\t\t\t\t*****************\n");
	
}
TeaNode *CreatTeaNode()
{
	TeaNode *pTeaNode = (TeaNode *)malloc(sizeof(TeaNode));                                            
	printf("Input information (Id,Passwd,Name,Sex):\n");
	
	printf("please input Id: ");
	scanf("%d",&pTeaNode->iTeaId);
	printf("please input passwd: ");
	getchar();
	scanf("%s",pTeaNode->acTeaPasswd);
	printf("please input name: ");
	scanf("%s",pTeaNode->acTeaName);
	printf("please input sex: ");
	getchar();
	pTeaNode->cSex = getchar();
	
	pTeaNode->pNextNode = NULL;

	return pTeaNode;
}

TeaNode * findTeaNode(const TeaHead *pTeaHead, const char caName[NAME_LEN])
//按教师姓名查找教师
{
	if (NULL == pTeaHead || NULL == caName)
	{
		return NULL;
	}
	if (0 == strlen(caName))
	{
		return NULL;
	}

	TeaNode *pTeaNode = NULL;
	pTeaNode = pTeaHead->pFirstNode;
	while (NULL != pTeaNode)
	{
		if (0 == strcmp(caName, pTeaNode->acTeaName))
		{
			break;
		}
		pTeaNode = pTeaNode->pNextNode;
	}

	return pTeaNode;
}
void showTeaNodeInfo(const TeaNode *pTeaNode)//显示当前节点信息
{
	if (NULL == pTeaNode)
	{
		return;
	}

	printf("\n\n\t******************************NodeInfo*********************************\n");

	printf("\t教职号\t密码\t姓名\t性别\t\n");
	printf(" \t%d\t%s\t%s\t%c\t\n",pTeaNode->iTeaId,
	pTeaNode->acTeaPasswd,pTeaNode->acTeaName,pTeaNode->cSex);
	
	printf("\t******************************NodeInfo*********************************\n");
}
void AddTeacher(TeaHead *pTeaHead,TeaNode *pTeaNode)
//1，添加教师
{

	char cCon = '\0';
	do
	{	pTeaNode = CreatTeaNode(pTeaNode);
		 InsertTeaNode(pTeaHead,pTeaNode);
	
		while('\n' != getchar())
		{
		}
		printf("Continue add people ?Y/N:");
		
		cCon = getchar();
		getchar();

	}while('Y' == cCon || 'y' == cCon);

	//PrintfTeaList(pTeaHead);
	printf("\n\n");
}
void FindTeacher(TeaHead *pTeaHead,TeaNode *pTeaNode)
//2，查找教师
{
	char cCon = '\0';
	char caName[NAME_LEN] = {'\0'};
	do
	{
		printf("please input name to find: ");
		scanf("%s", caName);
		pTeaNode = findTeaNode(pTeaHead, caName);
		if (NULL != pTeaNode)
		{
			showTeaNodeInfo(pTeaNode);
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
void ChangeTeacher(TeaHead *pTeaHead,TeaNode *pTeaNode)
//3，改变教师信息
{
	char cCon = '\0';
	char caName[NAME_LEN] = {'\0'};
	
	do
	{
		printf("please input name to find to change: ");
		scanf("%s", caName);
		pTeaNode = findTeaNode(pTeaHead, caName);
		if (NULL != pTeaNode)
		{
			showTeaNodeInfo(pTeaNode);
			changeTeaNodeInfo(pTeaNode);
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
void DeleteTeacher(TeaHead *pTeaHead,TeaNode *pTeaNode)
//4,删除教师
{
	
	char cCon = '\0';
	char caName[NAME_LEN] = {'\0'};
	do
	{
		printf("please input name to delete: ");
		scanf("%s", caName);
	
		deleteTeaNode(pTeaHead, caName);
		PrintfTeaList(pTeaHead);
		
		while ('\n' != getchar())
		{}
		printf("Continue find people ? Y/N: ");
		cCon = getchar();
		getchar();
	}while('Y' == cCon || 'y' == cCon);
	
}
int LookTeachoice()//管理员查看教师信息方式
{
	int look = 0;
	printf("\n\t\t***************\n\n");
	printf("\t\t1,按姓名查找\n");
	printf("\t\t2,查看所有教师信息\n");
	printf("\t\t0, 返回\n");
	printf("\n\t\t***************\n\n");
	
	printf("Input choice look: ");
	scanf("%d", &look);
	while ('\n' != getchar())
	{}
	return look;
}
void LookTeaWay(TeaHead *pTeaHead,TeaNode *pTeaNode)//管理员查看教师信息
{
	int icho = 0;
	while(1)
	{
		icho = LookTeachoice();
		switch(icho)
		{
			case 1:
				FindTeacher(pTeaHead,pTeaNode);
				break;
			case 2:
				PrintfTeaList(pTeaHead);
				break;
			case 0:
				return;
				break;
			default:
			break;

		}

	}

}
int changeTeaChoice()
{
	int iChoice = 0;
	printf("\n\n***************\n");
	printf("1, 修改名字\n");
	printf("2, 修改教职工号\n");
	printf("3, 修改性别\n");
	printf("0, 返回\n");
	printf("Input choice: ");
	scanf("%d", &iChoice);
	while ('\n' != getchar())
	{}

	return iChoice;
}
void getTeaName(char caName[NAME_LEN])
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

int getTeaId()
{
	int Id = 0;
	printf("\n\n**************\n");
	while (1) 
	{
		printf("please input new Id: ");
		if (scanf("%d", &Id))
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

	return Id;
}

char getTeaSex()
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
void changeTeaNodeInfo(TeaNode *pTeaNode)
{
	if (NULL == pTeaNode)
	{
		return;
	}

	char caName[NAME_LEN] = {'\0'};
	int iChoice = 0;
	while (1)
	{
		iChoice = changeTeaChoice();
		switch (iChoice)
		{
			case 1:
				getTeaName(caName);
				strcpy(pTeaNode->acTeaName, caName);
				break;
			case 2:
				pTeaNode->iTeaId = getTeaId();
				break;
			case 3:
				pTeaNode->cSex = getTeaSex();
				break;
			case 0:
				return;
			default:
				break;
		}
		showTeaNodeInfo(pTeaNode);
	}
}
void deleteTeaNode(TeaHead *pTeaHead, char caName[NAME_LEN])
{
	if (NULL == pTeaHead || NULL == caName)
	{
		return;
	}
	if (0 == strlen(caName))
	{
		return;
	}

	TeaNode *pTeaNodeCur = NULL;
	TeaNode *pTeaNodePre = NULL;

	pTeaNodeCur = pTeaHead->pFirstNode;
	pTeaNodePre = pTeaNodeCur;

	while (NULL != pTeaNodeCur)
	{
		if (0 == strcmp(caName, pTeaNodeCur->acTeaName))
		{
			break;
		}
		pTeaNodePre = pTeaNodeCur;
		pTeaNodeCur = pTeaNodeCur->pNextNode;
	}

	if (NULL != pTeaNodeCur)
	{
		if (pTeaNodeCur == pTeaNodePre)    //第一个节点匹配
		{
			pTeaHead->pFirstNode = pTeaNodeCur->pNextNode;
		}
		else if (NULL == pTeaNodeCur->pNextNode)    //最后一个节点匹配
		{
			pTeaNodePre->pNextNode = NULL;
		}
		else    //中间某个节点匹配
		{
			pTeaNodePre->pNextNode = pTeaNodeCur->pNextNode;
		}

		free(pTeaNodeCur);
		pTeaNodeCur = NULL;
		pTeaHead->iTeaLen--;
	}
}

