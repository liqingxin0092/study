#include <stdio.h>
#include <string.h>
#include<math.h>
#include <windows.h>
#include <string.h>
#include "contact.h"

void menu()
{
	printf("*************************************************\n");
	printf("********* 1.  add           2.  del      ********\n");
	printf("********* 3.  search        4.  modify   ********\n");
	printf("********* 5.  show          6.  sort     ********\n");
	printf("********* 0.  exit                       ********\n");
	printf("*************************************************\n");
	printf("*************************************************\n");
}
int main()
{
	Contact con;
	InitContact(&con);
	int input = 0;
	do {

		menu();
		printf("��ѡ����\n");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			add(&con);
			break;
		case 2:
			del(&con);
			break;
		case 3:
			search(&con);
			break;
		case 4:
			modify(&con);
			break;
		case 5:
			show(&con);
			break;
		case 6:
			sort(&con);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);


	return 0;
}