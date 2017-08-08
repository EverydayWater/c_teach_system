#ifndef TEACHER_SELF_H
#define TEACHER_SELF_H

#include "public.h"
#include "teacher.h"
#include "student.h"

int TeaSelfInfor();
void TeaSelfSelect(StuHead *pStuHead,StuNode *pStuNode,TeaNode *pTeaNode);
void EntryTeacherSelf(StuHead *pStuHead,StuNode *pStuNode,TeaHead *pTeaHead,TeaNode *pTeaNode);

void changeStuGread(StuHead *pStuHead,StuNode *pStuNode);
int StuGradeChange();
void qSortStuGread(StuHead *pStuHead,StuNode *pStuNode);
int StuGradeSort();
void ModefyTeaSecret(TeaNode *pTeaNode);





#endif
