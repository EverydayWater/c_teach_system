#include "../publicModel/student.h"

	int StuFunctionSelect()
	{
		int SeekStu = 0;
		printf("\n\t\t***************\n\n");
		printf("\t\t1,添加一个学生\n");
		printf("\t\t2,查看学生\n");
		printf("\t\t3,修改学生信息\n");
		printf("\t\t4,删除学生\n");
		printf("\t\t0, 返回\n");
		printf("\n\t\t***************\n\n");
	
		printf("Input choice look: ");
		scanf("%d", &SeekStu);
		while ('\n' != getchar())
		{}
		return SeekStu;

	}

		
void Stuselect(StuHead *pStuHead,StuNode *pStuNode)
{	
//	StuHead *pStuHead = NULL;
//	pStuHead = CreatEmptyList();
	
//	StuNode *pStuNode = NULL;
	int select = 0;
	while (1)
	{
		select = StuFunctionSelect();
		switch (select)
		{
			case 1:
				AddStudent(pStuHead,pStuNode);	
				break;
			case 2:
				LookWay(pStuHead,pStuNode);//在student.c 中
				break;
			case 3:
				ChangeStu(pStuHead,pStuNode);	
				break;
			case 4:
				DeleteStu(pStuHead,pStuNode);	
				break;
			case 0:
				return;
			default:
				break;
		}
	}
}
	
		
	
	
