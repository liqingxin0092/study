#include <stdio.h>
#include <stdlib.h>

int main()
{
	//����
	int* p = (int *)malloc(40);
	if (p == NULL)
		return 1;

	//����
	int* ptr = (int*)realloc(p,80);
	if (ptr == NULL)
		return 2;
	else
	{
		p = ptr;
		ptr = NULL;
	}
	 
	//ʹ��
	for (int i = 0; i < 20; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < 20; i++)
	{
		printf("%d ",p[i]);
	}

	//�ͷ�
	free(p);

	return 0;
}