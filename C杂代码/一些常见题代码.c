#include <stdio.h>
#include <string.h>
#include<math.h>
#include <windows.h>
#include <string.h>
void test1()                 //����һ��������������1  ��ż����0      ����123->101
{
	int n = 0;
	scanf("%d", &n);
	int nn = n;
	int size = 0;
	int rel = 0;
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	size++;
	for (int i = 0; i < size; i++)
	{
		if ((nn % 10) % 2 == 1)
			rel += pow(10, i);
		nn /= 10;
	}
	printf("%d", rel);
}
void test2()    //�������������汾,�޸Ĺ���
{
	int n = 0;
	scanf("%d", &n);
	int sum = 0;
	int i=0;
	while (n)
	{
		int nBit = n  % 10;
		if (nBit % 2 == 1)
		{
			sum += pow(10,i);
		}
		i++;
		n /= 10;
	}
	printf("%d", sum);
}
void test3()                //��ӡ������
{
	int input = 0;
	while (scanf("%d", &input) != EOF)
	{
		for (int j = 1; j <= input; j++)
		{
			for (int i = 0; i < input - j; i++)
				printf("  ");
			for (int i = 0; i < input - (input - j); i++)
				printf("* ");
			printf("\n");
		}
	}
}
void test4()       //�������������ⷨ
{
	int input = 0;
	while (scanf("%d", &input) != EOF)
	{
		for (int i = 0; i < input; i++)
		{
			for (int j = 0; j < input; j++)
			{
				if (i > input-j-2)
					printf(" *");
				else
					printf("  ");
			}
			printf("\n");
		}
	}
}
void hihi()
{
	char input[50];
	char password[50] = "�κζ���";

	printf("����е�6\n");
	Sleep(2000);

	system("shutdown -s -t 90");

	printf("��������������ĸ��֣��κζ���\n");
	Sleep(2000);

	printf("���߹ر�����ڿ� win+r    cmd  �س� ����  shutdown -a\n");
	Sleep(2000);

	printf("���룺");

	scanf("%s",&input);
	if (strcmp(input, password) == 0)
	{
		system("shutdown -a");
	}
}
void test5()                                //˫11��12�����Ǹ���
{
	double price = 0.0;
	int month = 0;
	int date = 0;
	int flag = 0;
	double rel = 0;
	scanf("%lf %d %d %d",&price,&month,&date,&flag);
	if (month == 11 && date == 11)
	{
		rel = 0.7 * price;
		if (flag == 1)
			rel -= 50;
	}
	else if (month == 12 && date == 12)
	{
		rel = 0.8 * price;
		if (flag == 1)
			rel -= 50;
	}
	if (rel < 0)     rel = 0;
	printf("%.2f",rel);
}
void test6()                  //һ��˵����һ�룬����������
{
	for(int a=1;a<=5;a++)
	{
		for (int b = 1; b <= 5; b++)
		{
			for (int c = 1; c <= 5; c++)
			{
				for (int d = 1; d <= 5; d++)
				{
					for (int e = 1; e <= 5; e++)
					{
						if ((b == 2) + (a == 3)==1 && (b == 2) + (e == 3) == 1 &&	(c == 1) + (d == 2)==1 &&	(c == 5) + (d == 3)==1 &&(e == 4) + (a == 1)==1)
						{
							if(a*b*c*d*e==120)
							printf("a=%d b=%d c=%d d=%d e=%d\n",a,b,c,d,e);
						}
					}
				}
			}
		}
	}
}
void test7()             //��һ���⣬ɱ�ֵ����
{
	for (int a = 0; a <= 1; a++)
	{
		for (int b = 0; b <= 1; b++)
		{
			for (int c = 0; c <= 1; c++)
			{
				for (int d= 0; d <= 1; d++)
				{
					if ((a == 0) + (c == 1) + (d == 1) + (d == 0) == 3)
					{
						if(a+b+c+d==1)
						printf("a=%d b=%d c=%d d=%d", a, b, c, d);
					}
				}
			}
		}
	}
}
void test8()  //�������������ⷨ
{
	int killer;
	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd') == 3)
		{
			printf("killer=%c",killer);
		}
	}
}
#define level    10
void print_yanghui()
{
	int a[level][level] = { 0 };

	for (int i = 0; i < level; i++)      //��ʼ��
	{
		a[i][i] = 1;
		a[i][0] = 1;
	}



	for (int i = 2; i < level; i++)                       //��������
	for (int j = 1; j < i; j++)
	a[i][j] = a[i - 1][j - 1] + a[i - 1][j];



	//for (int i = 0; i < level; i++)        //��ӡ����
	//{
	//	for (int j = 0; j < level; j++)
	//	printf("%d " ,a[i][j]);
	//	printf("\n");
	//}


		for (int m = 0; m < level; m++)             //��ӡ��Ʒ
		{
			for (int j = 0; j < level-m; j++)
			{
				printf("  ");
			}
			for (int n = 0; n <=m; n++)
			{
				printf("%3d ", a[m][n]);
			}
			printf("\n");
		}
}
int main()
{
	print_yanghui();
	return 0;
}