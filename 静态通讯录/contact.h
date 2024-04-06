#pragma once
#include <string.h>
#include <stdlib.h> 

#define MAX        100
#define MAX_NAME    20
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

typedef struct
{
	People people[MAX];    //����˵���Ϣ
	int count; //��¼����
}Contact;

//��ʼ����ϵ��
void InitContact( Contact* p);

//������ϵ��
void add(Contact* p);

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