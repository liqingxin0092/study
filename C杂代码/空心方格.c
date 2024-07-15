#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma execution_character_set("utf-8")  
int n, i;
int  f()
{
	for (i = 0; i < n; i++) 
		printf("8 ");
	return 0;
}
void test()
{
	while(scanf("%d",&n)!=EOF)
	{
		for (i = 0; i < n; i++)
		{
			printf("8 ");
		}
		printf("\n");
		for (i = 0; i < n - 2; i++)
		{
			printf("8");
			for (int j = 0; j < n - 2; j++)
				printf("  ");
			printf(" ");
			printf("8\n");
		}
		!(n > 1) || f();       //左侧接收一个非返回void型函数
		printf("\n");
	}
	
}



int main()
{
	test();
	return 0;
}