#ifndef MAIN_H
#define MAIN_H

#include "public.h"
#include "student.h"
#include "teacher.h"
#include "admin.h"

int mainchangeChoice();
void LoginSystem(StuHead *pStuHead,StuNode *pStuNode,TeaHead *pTeaHead,TeaNode *pTeaNode,Adm *pst);
void SaveTeaFile(TeaHead *pTeaHead);
void ReadTeaFile(TeaHead *pTeaHead);
void SaveStuFile(StuHead *pStuHead);
void ReadStuFile(StuHead *pStuHead);
void SaveAdmFile(Adm *pst);
void ReadAdmFile(Adm *pst);
void destroyStu(StuHead *pStuHead,StuNode *pStuNode);
void destroyTea(TeaHead *pTeaHead,TeaNode *pTeaNode);
void destroyAdm(Adm *pst);

#endif
