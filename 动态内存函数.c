#include <stdio.h>
#include <stdlib.h>

int main()
{
	//开辟
	int* p = (int *)malloc(40);
	if (p == NULL)
		return 1;

	//扩容
	int* ptr = (int*)realloc(p,80);
	if (ptr == NULL)
		return 2;
	else
	{
		p = ptr;
		ptr = NULL;
	}
	 
	//使用
	for (int i = 0; i < 20; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < 20; i++)
	{
		printf("%d ",p[i]);
	}

	//释放
	free(p);

	return 0;
}