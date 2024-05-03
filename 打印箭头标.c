#pragma execution_character_set("utf-8")  
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int i,j;
	int input = 0;
	while (scanf("%d", &input) != EOF)
	{
		for (i = 0; i < input+1 ; i++)
		{
			for (j = 0; j < 2 * (input - i); j++)
				printf(" ");
			for (j = 0; j < i+1; j++)
				printf("*");
			printf("\n");
		}
		for (i = 0; i < input; i++)
		{
			for (j = 0; j <2*(i+1) ; j++)
				printf(" ");
			for (j = 0; j < input-i; j++)
				printf("*");
			printf("\n");
		}

	}
	return 0;
}