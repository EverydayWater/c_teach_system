#include "./publicModel/main.h"
#include "./publicModel/admin.h"
#include "./publicModel/student_self.h"
#include "./publicModel/teacher_self.h"

int main(int argc,char *argv[])
{
	/*分别创建学生、教师、管理员链表*/
	StuHead *pStuHead = NULL;
	pStuHead = CreatEmptyList();
	StuNode *pStuNode = NULL;
	
	TeaHead *pTeaHead = NULL;
	pTeaHead = CreatTeaEmptyList();
	TeaNode *pTeaNode = NULL;

	Adm *pst = NULL;
	pst = CreatNewAdm();

	/*从文件中把教师、学生、管理员信息读到链表中*/
	ReadTeaFile(pTeaHead);
	ReadStuFile(pStuHead);
	ReadAdmFile(pst);
	
	/*在链表中处理数据*/
	LoginSystem(pStuHead,pStuNode,pTeaHead,pTeaNode,pst);//在mainControl.c文件中
									//	头文件为main.h
	/*处理数据后保存到文件中*/
	SaveTeaFile(pTeaHead);
	SaveStuFile(pStuHead);
	SaveAdmFile(pst);

	/*销毁链表*/
	destroyTea(pTeaHead,pTeaNode);
	destroyStu(pStuHead,pStuNode);
	destroyAdm(pst);

	return 0;
}
