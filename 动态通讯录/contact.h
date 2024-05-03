#pragma once
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

#define MAX        100
#define MAX_NAME    20
#define INIT_NUM        2
#define ADD_NUM       3
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

//静态版本
//typedef struct
//{
//	People people[MAX];    //存放人的信息
//	int count; //记录人数
//}Contact;

//动态版本
typedef struct
{
	People* data;    //存放人的信息
	int count; //记录人数
	int capacity;//当前通讯录容量
}Contact;

//初始化联系人
int  InitContact( Contact* p);

//空间回收

void distory_data(Contact* p);

//增加联系人
int add(Contact* p);

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

//保存
int save(const Contact* p);

//加载
int LoadContact(Contact* p);