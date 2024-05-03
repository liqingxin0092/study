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
//�˵���Ϣ 

typedef struct 
{
	char name[MAX_NAME];
	int age;
	char sex[10];
	char tele[20];
	char addr[30];
}People;

//ͨѶ¼��Ϣ

//��̬�汾
//typedef struct
//{
//	People people[MAX];    //����˵���Ϣ
//	int count; //��¼����
//}Contact;

//��̬�汾
typedef struct
{
	People* data;    //����˵���Ϣ
	int count; //��¼����
	int capacity;//��ǰͨѶ¼����
}Contact;

//��ʼ����ϵ��
int  InitContact( Contact* p);

//�ռ����

void distory_data(Contact* p);

//������ϵ��
int add(Contact* p);

//��ʾͨѶ¼
void show(const Contact* p);

//ɾ������
void del(Contact* p);

//����
void search(const Contact* p);

//�޸�
void 	modify(Contact* p);

//����
void sort(Contact* p);

//����
int save(const Contact* p);

//����
int LoadContact(Contact* p);