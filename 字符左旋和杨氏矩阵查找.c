#include <stdio.h>
#include <string.h>
#include<math.h>
#include <windows.h>
#include <string.h>
void string_left_turn(char* str, int length)
{
	for (int i = 0; i < length; i++)          //lengthΪִ�л���������Ԫ�Ĵ���
	{
		        //ִ�л���������Ԫ
		char t = *str;                  //���浱ǰ�ַ�����һ���ַ�
		char* p;                 
		for (p = str + 1; *p != '\0'; p++)       //pָ���ʼָ��ڶ����ַ�   ����Χ���ڶ����ַ�һֱ��'\0'
		{
			( - 1)[p] = *p;            //�ַ���ǰŵһ��
		}
		*(p - 1) = t;        //֮ǰ��һ���ַ�Ų�����
	}
}
char arr[] = "abcd";
void reverse(char *arr,int length)           //�ַ�������
{
	for (int i = 0; i < length/2; i++)
	{
		char t = *(arr + i);
		*(arr + i) = *(arr+length-i-1);
		*(arr + length - i - 1) = t;
	}
}
void  string_left_turn_2(char *str,int num)       //���õ���ʵ������
{
	int size = strlen(str);
	reverse(str, num);                   //��ͷ������
	reverse(str + num, size - num);      //������ĩβ
	reverse(str,size);                //���嵹��

	printf("%s ", str);
}

int arr0[4][4] = { 
	1, 2, 3, 4,
	5, 6, 7, 8,
	9,10,11,12,
	13,14,15,16, 
};

typedef struct {
	int px;
	int py;
}loca;
loca  yang_find(int (*arr)[4], int row, int col, int dest)                         //�����Ͼ����в���
{
	int x = 0;
	int y = col - 1;
	loca p = { -1,-1 };                     //���ؽṹ��
	while (x < row && y >= 0)
	{
		if (dest < arr[x][y])
			y--;
		else if (dest > arr[x][y])
			x++;
		else
		{
			p.px = x;
			p.py = y;
			return p;
		}
	}
	return p;
}

int  yang_find_2(int(*arr)[4], int row, int col, int dest,int *px,int *py)                         //�����Ͼ����в���
{
	int x = 0;
	int y = col - 1;
	                 //����ַ��������ģ�ⷵ��ֵ
	while (x < row && y >= 0)
	{
		if (dest < arr[x][y])
			y--;
		else if (dest > arr[x][y])
			x++;
		else
		{
			*px= x;
			*py = y;
			return 1;
		}
	}
	return -1;
}

int main()
{
	//loca pp;
	//pp=yang_find(arr0, 4, 4, 16);
	//printf("%d %d",pp.px ,pp.py );

	int a = 0, b = 0;
	yang_find_2(arr0, 4, 4, 7,&a,&b);
	printf("%d %d",a ,b);
	return 0;
}