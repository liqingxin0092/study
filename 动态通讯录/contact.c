#include "contact.h"


//��̬�汾
//void InitContact(Contact* p)
//{
//	assert(p);
//	p->count = 0;
//	memset(p->data,0,sizeof(p->data));
//}

//��̬�汾
int InitContact(Contact* p)
{
	assert(p);
	p->count = 0;
	p->data = (People*)calloc(INIT_NUM, sizeof(People));
	if (p->data == NULL)
	{
		printf("%s",strerror(errno));
		return 1;
	}
	p->capacity = INIT_NUM;

	//�����ļ���Ϣ��ͨѶ¼��
	LoadContact(p);
	return 0;
}

static void zengrong(Contact* p)
{
	//����
	if (p->count == p->capacity)
	{
		People* ptr = (People*)realloc(p->data, (p->capacity + ADD_NUM) * sizeof(People));
		if (ptr == NULL)
		{
			printf("%s", strerror(errno));
			return 1;
		}
		else
		{
			p->data = ptr;
			ptr = NULL;
			p->capacity += ADD_NUM;
			printf("����\n");
		}
	}
}
void distory_data(Contact* p)
{
	assert(p);
	free(p->data);
	p->data = NULL;

}
//����
int LoadContact(Contact* p)
{
	assert(p);
	FILE* pf = fopen("D:\\OneDrive\\Desktop\\��\\study\\��̬ͨѶ¼\\���ݱ���.txt", "rb");
	if (pf == NULL)
		return 1;

	People temp = { 0 };
	while (fread(&temp, sizeof(People), 1, pf) == 1)
	{
		zengrong(p);
		p->data[p->count] = temp;
		p->count++;
	}



	fclose(pf);
	pf == NULL;
}
//��̬�汾
//void add(Contact* p)
//{
//	assert(p);
//	if (p->count == MAX)
//	{
//		printf("ͨѶ¼����\n");
//		return;
//	}
//	printf("����������:>");
//	scanf("%s", p->data[p->count].name);     //�������������ǵ�ַ
//	printf("����������:>");
//	scanf("%d", &(p->data[p->count].age));
//	printf("�������Ա�:>");
//	scanf("%s", p->data[p->count].sex);
//	printf("������绰:>");
//	scanf("%s", p->data[p->count].tele);
//	printf("�������ַ:>");
//	scanf("%s", p->data[p->count].addr);
//
//	p->count++;
//	printf("���ӳɹ���\n");
//}

//���� ����
int  save(const Contact* p)
{
	assert(p);
	FILE* pf = fopen("D:\\OneDrive\\Desktop\\��\\study\\��̬ͨѶ¼\\���ݱ���.txt","wb");
	if (pf == NULL)
		return 1;

	int i = 0;
	for (i = 0; i < p->count; i++)
	{
		fwrite(p->data+i,sizeof(People),1,pf);
	}


	fclose(pf);
	pf == NULL;
}
//��̬�汾
int  add(Contact* p)
{
	assert(p);

	//����
	zengrong(p);

	printf("����������:>");
	scanf("%s", p->data[p->count].name);     //�������������ǵ�ַ
	printf("����������:>");
	scanf("%d", &(p->data[p->count].age));
	printf("�������Ա�:>");
	scanf("%s", p->data[p->count].sex);
	printf("������绰:>");
	scanf("%s", p->data[p->count].tele);
	printf("�������ַ:>");
	scanf("%s", p->data[p->count].addr);

	p->count++;
	printf("���ӳɹ���\n");

	return 0;
}

void show(const Contact* p)       //��ʾ
{
	assert(p);
	printf("%20s\t%3s\t%5s\t%12s\t%20s\n", "����","����","�Ա�","�绰","��ַ");
	for (int i = 0; i < p->count; i++)
	{
		printf("%20s\t%3d\t%5s\t%12s\t%20s\n",  p->data[i].name,
												p->data[i].age, 
												p->data[i].sex,
												p->data[i].tele,
												p->data[i].addr);
	}

}
static int FindByName(const Contact* p, char name[])
{
	assert(p);
	for (int i = 0; i < MAX; i++)
	{
		if (0==strcmp(p->data[i].name, name) )
			return i;
	}
	return -1;

}
void del(Contact* p)
{
	assert(p);
	if (p->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}

	char name[MAX_NAME];
	printf("����������Ҫɾ��������:>");
	scanf("%s", name);

	//ɾ��
	//1.����
	int pos=FindByName(p,name);
	if (pos == -1)
	{
		printf("��Ҫɾ�����ֲ�����!\n");
		return;
	}
	//2.ɾ��
	for (int i = pos; i < p->count - 1; i++)
	{
		p->data[i] = p->data[i + 1];
	}
	p->count--;
	printf("ɾ���ɹ���\n");
}

void search(const Contact* p)
{
	assert(p);
	if (p->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}

	char name[MAX_NAME];
	printf("����������Ҫ���ҵ�����:>");
	scanf("%s", name);


	//����
	int pos = FindByName(p, name);
	if (pos == -1)
	{
		printf("��Ҫ���ҵ��˵����ֲ�����!\n");
		return;
	}
	//��ʾ
	printf("%20s\t%3s\t%5s\t%12s\t%20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%20s\t%3d\t%5s\t%12s\t%20s\n", p->data[pos].name,
		p->data[pos].age,
		p->data[pos].sex,
		p->data[pos].tele,
		p->data[pos].addr);
}

void modify(Contact* p)
{
	assert(p);
	if (p->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�");
		return;
	}

	char name[MAX_NAME];
	printf("����������Ҫ�޸ĵ�����:>");
	scanf("%s", name);

	//����
	int pos = FindByName(p, name);
	if (pos == -1)
	{
		printf("��Ҫ�޸ĵ��˵����ֲ�����!\n");
		return;
	}
	//�޸�
	printf("Ҫ�޸ĵ��˵���Ϣ�Ѿ����ҵ�,�뿪ʼ�޸�\n");
	printf("����������:>");
	scanf("%s", p->data[p->count].name);     //�������������ǵ�ַ
	printf("����������:>");
	scanf("%d", &(p->data[pos].age));
	printf("�������Ա�:>");
	scanf("%s", p->data[pos].sex);
	printf("������绰:>");
	scanf("%s", p->data[pos].tele);
	printf("�������ַ:>");
	scanf("%s", p->data[pos].addr);

	printf("�޸ĳɹ���\n");
}
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((People*)e1)->name,((People*)e2)->name);
}
void sort(Contact* p)
{
	assert(p);
	qsort(p->data, p->count, sizeof(p->data[0]), cmp_by_name);
}