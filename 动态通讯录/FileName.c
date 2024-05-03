#include <stdio.h>
#include <string.h>
#include<math.h>
#include <windows.h>
#include <string.h>
#include "contact.h"

enum mode        //������װ
{
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Show,
	Sort,
};

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
		case Add:
			add(&con);
			break;
		case Del:
			del(&con);
			break;
		case Search:
			search(&con);
			break;
		case Modify:
			modify(&con);
			break;
		case Show:
			show(&con);
			break;
		case Sort:
			sort(&con);
			break;
		case Exit:
			save(&con);
			distory_data(&con);
			printf("�˳�\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);


	return 0;
}