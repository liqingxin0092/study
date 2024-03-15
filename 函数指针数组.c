#include <stdio.h>
#include<time.h>
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mod(int a, int b)
{
	return a * b;
}
int (*arr[4])(int , int ) = {0,&add,&sub,&mod};
void menu()
{
	printf("0.退出 1.加法 2.减法 3.乘法\n");
}
int main()
{
	int input ,a,b,rel;
	do 
	{
		menu();
		printf("please choose your calculate rule:\n");
		scanf("%d", &input);
		if (input == 0)
		{
			printf("exit");
		}
		else
		{
			printf("please input your num\n");
			scanf("%d %d", &a, &b);
			rel = arr[input](a, b);
			printf("%d\n", rel);
		}
	} while (input);
	return 0;
}