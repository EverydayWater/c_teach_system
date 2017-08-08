#ifndef ADMIN_H
#define ADMIN_H

#include "student.h"
#include "teacher.h"
#include "public.h"

#define ADM_NAME_LEN 20


typedef struct Adm
{
	char acAdmName[ADM_NAME_LEN];
	int iAdmPass;

}Adm;

int AdminChoice();
void AdminStu(StuHead *pStuHead,StuNode *pStuNode,
TeaHead *pTeaHead,TeaNode *pTeaNodem,Adm *pst);
void EntryAdmin(StuHead *pStuHead,StuNode *pStuNode,TeaHead *pTeaHead,TeaNode *pTeaNode,Adm *pst);
Adm *CreatNewAdm();

void ModefyAdminSecret(Adm *pst);
int getAdmPass();

#endif
