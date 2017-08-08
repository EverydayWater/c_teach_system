DIR_INC = ./publicModel
DIR_TEACHERMODEL = ./teacherModel
DIR_STUDENTMODEL = ./studentModel
DIR_ADMINMODEL = ./adminModel
DIR_MAINCTROL = ./mainControl

SOURCE = ${wildcard ${DIR_ADMINMODEL}/*.c}
SOURCE += ${wildcard ${DIR_MAINCTROL}/*.c}
SOURCE += ${wildcard ${DIR_TEACHERMODEL}/*.c}
SOURCE += ${wildcard ${DIR_STUDENTMODEL}/*.c}
SOURCE += main.c
#SOURCE += ${wildcard ${DIR_INC}/*.h}

#OBJS = ${patsubst %.c,%.o,$(SOURCE)}


OBJ = main
CC = gcc
CFLAGS = -g -Wall

$(OBJ):$(SOURCE)
	$(CC) $(CFLAGS) -o $@ $^


.PHONY:clean
clean:
	$(RM) -f *.o main

