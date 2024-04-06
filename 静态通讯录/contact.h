#pragma once
#include <string.h>
#include <stdlib.h> 

#define MAX        100
#define MAX_NAME    20
//人的信息 

typedef struct 
{
	char name[MAX_NAME];
	int age;
	char sex[10];
	char tele[20];
	char addr[30];
}People;

//通讯录信息

typedef struct
{
	People people[MAX];    //存放人的信息
	int count; //记录人数
}Contact;

//初始化联系人
void InitContact( Contact* p);

//增加联系人
void add(Contact* p);

//显示通讯录
void show(const Contact* p);

//删除个例
void del(Contact* p);

//查找
void search(const Contact* p);

//修改
void 	modify(Contact* p);

//排序
void sort(Contact* p);