#include "contact.h"


//静态版本
//void InitContact(Contact* p)
//{
//	assert(p);
//	p->count = 0;
//	memset(p->data,0,sizeof(p->data));
//}

//动态版本
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

	//加载文件信息到通讯录中
	LoadContact(p);
	return 0;
}

static void zengrong(Contact* p)
{
	//增容
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
			printf("增容\n");
		}
	}
}
void distory_data(Contact* p)
{
	assert(p);
	free(p->data);
	p->data = NULL;

}
//加载
int LoadContact(Contact* p)
{
	assert(p);
	FILE* pf = fopen("D:\\OneDrive\\Desktop\\库\\study\\动态通讯录\\数据保存.txt", "rb");
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
//静态版本
//void add(Contact* p)
//{
//	assert(p);
//	if (p->count == MAX)
//	{
//		printf("通讯录已满\n");
//		return;
//	}
//	printf("请输入名字:>");
//	scanf("%s", p->data[p->count].name);     //数组名本来就是地址
//	printf("请输入年龄:>");
//	scanf("%d", &(p->data[p->count].age));
//	printf("请输入性别:>");
//	scanf("%s", p->data[p->count].sex);
//	printf("请输入电话:>");
//	scanf("%s", p->data[p->count].tele);
//	printf("请输入地址:>");
//	scanf("%s", p->data[p->count].addr);
//
//	p->count++;
//	printf("增加成功！\n");
//}

//保存 数据
int  save(const Contact* p)
{
	assert(p);
	FILE* pf = fopen("D:\\OneDrive\\Desktop\\库\\study\\动态通讯录\\数据保存.txt","wb");
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
//动态版本
int  add(Contact* p)
{
	assert(p);

	//增容
	zengrong(p);

	printf("请输入名字:>");
	scanf("%s", p->data[p->count].name);     //数组名本来就是地址
	printf("请输入年龄:>");
	scanf("%d", &(p->data[p->count].age));
	printf("请输入性别:>");
	scanf("%s", p->data[p->count].sex);
	printf("请输入电话:>");
	scanf("%s", p->data[p->count].tele);
	printf("请输入地址:>");
	scanf("%s", p->data[p->count].addr);

	p->count++;
	printf("增加成功！\n");

	return 0;
}

void show(const Contact* p)       //显示
{
	assert(p);
	printf("%20s\t%3s\t%5s\t%12s\t%20s\n", "名字","年龄","性别","电话","地址");
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
		printf("通讯录为空！");
		return;
	}

	char name[MAX_NAME];
	printf("请输入你想要删除的名字:>");
	scanf("%s", name);

	//删除
	//1.查找
	int pos=FindByName(p,name);
	if (pos == -1)
	{
		printf("你要删的名字不存在!\n");
		return;
	}
	//2.删除
	for (int i = pos; i < p->count - 1; i++)
	{
		p->data[i] = p->data[i + 1];
	}
	p->count--;
	printf("删除成功！\n");
}

void search(const Contact* p)
{
	assert(p);
	if (p->count == 0)
	{
		printf("通讯录为空！");
		return;
	}

	char name[MAX_NAME];
	printf("请输入你想要查找的名字:>");
	scanf("%s", name);


	//查找
	int pos = FindByName(p, name);
	if (pos == -1)
	{
		printf("你要查找的人的名字不存在!\n");
		return;
	}
	//显示
	printf("%20s\t%3s\t%5s\t%12s\t%20s\n", "名字", "年龄", "性别", "电话", "地址");
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
		printf("通讯录为空！");
		return;
	}

	char name[MAX_NAME];
	printf("请输入你想要修改的名字:>");
	scanf("%s", name);

	//查找
	int pos = FindByName(p, name);
	if (pos == -1)
	{
		printf("你要修改的人的名字不存在!\n");
		return;
	}
	//修改
	printf("要修改的人的信息已经查找到,请开始修改\n");
	printf("请输入名字:>");
	scanf("%s", p->data[p->count].name);     //数组名本来就是地址
	printf("请输入年龄:>");
	scanf("%d", &(p->data[pos].age));
	printf("请输入性别:>");
	scanf("%s", p->data[pos].sex);
	printf("请输入电话:>");
	scanf("%s", p->data[pos].tele);
	printf("请输入地址:>");
	scanf("%s", p->data[pos].addr);

	printf("修改成功！\n");
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