#include <stdio.h>
#include <string.h>
#include<math.h>
#include <windows.h>
#include <string.h>
void string_left_turn(char* str, int length)
{
	for (int i = 0; i < length; i++)          //length为执行基本操作单元的次数
	{
		        //执行基本操作单元
		char t = *str;                  //保存当前字符串第一个字符
		char* p;                 
		for (p = str + 1; *p != '\0'; p++)       //p指针初始指向第二个字符   ，范围：第二个字符一直到'\0'
		{
			( - 1)[p] = *p;            //字符往前诺一个
		}
		*(p - 1) = t;        //之前第一个字符挪到最后
	}
}
char arr[] = "abcd";
void reverse(char *arr,int length)           //字符串倒序
{
	for (int i = 0; i < length/2; i++)
	{
		char t = *(arr + i);
		*(arr + i) = *(arr+length-i-1);
		*(arr + length - i - 1) = t;
	}
}
void  string_left_turn_2(char *str,int num)       //利用倒序实现左旋
{
	int size = strlen(str);
	reverse(str, num);                   //开头到数量
	reverse(str + num, size - num);      //数量到末尾
	reverse(str,size);                //整体倒序

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
loca  yang_find(int (*arr)[4], int row, int col, int dest)                         //在杨氏矩阵中查找
{
	int x = 0;
	int y = col - 1;
	loca p = { -1,-1 };                     //返回结构体
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

int  yang_find_2(int(*arr)[4], int row, int col, int dest,int *px,int *py)                         //在杨氏矩阵中查找
{
	int x = 0;
	int y = col - 1;
	                 //传地址，改数据模拟返回值
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