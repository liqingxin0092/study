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
		printf("通讯录已满\n");
		return;
	}
	printf("请输入名字:>");
	scanf("%s", p->people[p->count].name);     //数组名本来就是地址
	printf("请输入年龄:>");
	scanf("%d", &(p->people[p->count].age));
	printf("请输入性别:>");
	scanf("%s", p->people[p->count].sex);
	printf("请输入电话:>");
	scanf("%s", p->people[p->count].tele);
	printf("请输入地址:>");
	scanf("%s", p->people[p->count].addr);

	p->count++;
	printf("增加成功！\n");
}

void show(const Contact* p)       //显示
{
	assert(p);
	printf("%20s\t%3s\t%5s\t%12s\t%20s\n", "名字","年龄","性别","电话","地址");
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
		p->people[i] = p->people[i + 1];
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
	scanf("%s", p->people[p->count].name);     //数组名本来就是地址
	printf("请输入年龄:>");
	scanf("%d", &(p->people[pos].age));
	printf("请输入性别:>");
	scanf("%s", p->people[pos].sex);
	printf("请输入电话:>");
	scanf("%s", p->people[pos].tele);
	printf("请输入地址:>");
	scanf("%s", p->people[pos].addr);

	printf("修改成功！\n");
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