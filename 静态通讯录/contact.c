#include "contact.h"
#include "assert.h"
void InitContact(Contact* p)
{
	assert(p);
	p->count = 0;
	memset(p->people,0,sizeof(p->people));
}

void add(Contact* p)
{
	assert(p);
	if (p->count == MAX)
	{
		printf("ͨѶ¼����\n");
		return;
	}
	printf("����������:>");
	scanf("%s", p->people[p->count].name);     //�������������ǵ�ַ
	printf("����������:>");
	scanf("%d", &(p->people[p->count].age));
	printf("�������Ա�:>");
	scanf("%s", p->people[p->count].sex);
	printf("������绰:>");
	scanf("%s", p->people[p->count].tele);
	printf("�������ַ:>");
	scanf("%s", p->people[p->count].addr);

	p->count++;
	printf("���ӳɹ���\n");
}

void show(const Contact* p)       //��ʾ
{
	assert(p);
	printf("%20s\t%3s\t%5s\t%12s\t%20s\n", "����","����","�Ա�","�绰","��ַ");
	for (int i = 0; i < p->count; i++)
	{
		printf("%20s\t%3d\t%5s\t%12s\t%20s\n",  p->people[i].name,
												p->people[i].age, 
												p->people[i].sex,
												p->people[i].tele,
												p->people[i].addr);
	}

}
static int FindByName(const Contact* p, char name[])
{
	assert(p);
	for (int i = 0; i < MAX; i++)
	{
		if (0==strcmp(p->people[i].name, name) )
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
		p->people[i] = p->people[i + 1];
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
	printf("%20s\t%3d\t%5s\t%12s\t%20s\n", p->people[pos].name,
		p->people[pos].age,
		p->people[pos].sex,
		p->people[pos].tele,
		p->people[pos].addr);
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
	scanf("%s", p->people[p->count].name);     //�������������ǵ�ַ
	printf("����������:>");
	scanf("%d", &(p->people[pos].age));
	printf("�������Ա�:>");
	scanf("%s", p->people[pos].sex);
	printf("������绰:>");
	scanf("%s", p->people[pos].tele);
	printf("�������ַ:>");
	scanf("%s", p->people[pos].addr);

	printf("�޸ĳɹ���\n");
}
int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((People*)e1)->name,((People*)e2)->name);
}
void sort(Contact* p)
{
	assert(p);
	qsort(p->people, p->count, sizeof(p->people[0]), cmp_by_name);
}