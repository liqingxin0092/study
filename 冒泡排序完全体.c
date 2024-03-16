#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bubble_sort(int *arr,int size)
{
	int flag;
	for (int i = 0; i < size - 1; i++)
	{
		flag = 1;                                //优化
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				int t = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = t;
				flag = 0;
			}
			if (flag == 1)
				break;
		}
	}
}



void swap(char* a,char* b,int width)
{
	for (int i = 0; i < width; i++)
	{
		char t = *(a+i);
		*(a+i) = *(b+i);
		*(b+i) = t;
	}
}
int  cmp(const void* e1, const void* e2)          //比较函数
{
	return *(int*)e2 - *(int*)e1;     //两个数比较，最后返回正数，0，负数为比较依据          //根据需求更改
}
void bubble_sort_plus(void* arr, int size, int width, int (*cmp_function)(void* , void* ))
{
	int flag;
	for (int i = 0; i < size - 1; i++)
	{
		flag = 1;                                //优化
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (cmp_function((char*)arr + j * width, (char*)arr + (j + 1) * width)<0)
			{
				swap((char*)arr + j * width, (char*)arr + (j + 1) * width, width);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}





int arr[] = { 2,1,3,4,50,7,6,9,-1 };
int size1 = sizeof(arr) / sizeof(arr[0]);
void display_bubble()
{
	for (int i = 0; i < size1; i++)
	{
		printf("%d\n", arr[i]);
	}
}







struct stu
{
	char name[10];
	int age;
}stu[] = { {"pxd",11},{"zxd",12}};
int size2 = sizeof(stu) / sizeof(stu[0]);
int cmp_by_name(const void *e1,const void *e2)
{
	return strcmp(((struct stu*)e2)->name, ((struct stu*)e1)->name);//1对1对的比
}
int cmp_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e2)->age- ((struct stu*)e1)->age;
}
void display_qsort()
{
	for (int i = 0; i < size2; i++)
	{
		printf("%s ",stu[i].name);
		printf("%d\n", stu[i].age);
	}
}





int main()
{
	//bubble_sort(arr, size);
	//qsort(arr,size1,sizeof(arr[0]),cmp);    //数组首地址，元素个数，步距，一个决定顺序函数
	//display_bubble();
	//display_qsort();
	bubble_sort_plus(arr, size1, sizeof(arr[0]), cmp);
	display_bubble();
	return 0;
}
