#include "../publicModel/teacher.h"

int TeaFunctionSelect()
	{
		int SeekTea = 0;
		printf("\n\t\t***************\n\n");
		printf("\t\t1,添加一个教师\n");
		printf("\t\t2,查看教师信息\n");
		printf("\t\t3,修改教师信息\n");
		printf("\t\t4,删除教师\n");
		printf("\t\t0, 返回\n");
		printf("\n\t\t***************\n\n");
	
		printf("Input choice look: ");
		scanf("%d", &SeekTea);
		while ('\n' != getchar())
		{}
		
	return SeekTea;
}

		
void TeaSelect(TeaHead *pTeaHead,TeaNode *pTeaNode)
{	
//	TeaHead *pTeaHead = NULL;
//	pTeaHead = CreatTeaEmptyList();
	
//	TeaNode *pTeaNode = NULL;	
	int select = 0;
	while (1)
	{
		select = TeaFunctionSelect();
		switch (select)
		{
			case 1:
				AddTeacher(pTeaHead,pTeaNode);	
				break;
			case 2:
				LookTeaWay(pTeaHead,pTeaNode);
				break;
			case 3:
				ChangeTeacher(pTeaHead,pTeaNode);	
				break;
			case 4:
				DeleteTeacher(pTeaHead,pTeaNode);	
				break;
			case 0:
				return;
			default:
				break;
		}
	}
}	

