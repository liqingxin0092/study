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
	for (int i = 1; i < length/2; i++)
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
char str[20] = "abcde";
char st_r[] = "abcde";
int is_turn (char *a,char*b)        //�ж��ǲ�����ת���
{
	int size = strlen(str);
	for (int i = 1; i < size; i++)
	{
		string_left_turn(a, 1);    //���ǻ��a����
		if (strcmp(a, b) == 0)
			return 1;
	}
	return 0;
}


int my_strcmp(const char* arr1, const char* arr2, int length)        //�Ƚ��ַ�����
{
	for (int i = 0; i < length; i++)
	{
		if (*arr1 == *arr2)
		{
			arr1++; arr2++;
		}
		else
			return -1;
	}
	return 0;
}
int is_turn_2(char* a, char* b)                  //�ж��ǲ�����ת���
{
	strcat(str,str);      //����a=����aƴ����
	int size = strlen(b);
	while(*(a+size-1)!='\0')
	{
		if (my_strcmp(a, b, size) == 0)
			return 1;
		a++;
	}
	return -1;
}


int is_turn_3(char* a, char* b)
{
	/*strcat(str, str);     */    //����a=����aƴ����
	strcat(str,str,strlen(str));     //��n������ȶ�
	if (strstr(a, b) != NULL)
		return 1;
	return -1;
}
void test11()                          //���� ��ƽ������ż����ƽ����
{
	int x;
	int t = 0;
	int m = 0;
	float a = 0.0, b = 0.0;
	do {
		scanf("%d",&x);
		if (x % 2 == 1)
		{
			a += x;
			t++;
		}
		if(x%2==0)
		{
			b += x;
			if(x!=0)
			m++;
		}
	} while (x!=0);
	printf("%.2f %.2f", a / t, b / m);
}

void test12()                              //����ת��      
{
	int arr[10][10] = { 0 };
	int x, y;
	scanf("%d %d",&x,&y);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			printf("%d",*(*(arr+j)+i));
		}
		printf("\n");
	}
}
void fibonacci_arr_1()        //�������е���
{
	int a = 1, b = 1, c;
	int i = 10;
	while (i-- > 0)
	{
		c = a + b;
		a = b;
		b = c;
		printf("%d ",c);
	}
}
void fibonacci_arr_0()              //������������
{
	int o[10];
	o[0] = o[1] = 1;
	for (int i = 2; i < 10; i++)
	{
		i[o] = (i - 1)[o] + (i - 2)[o];
		printf("%d ", i[o]);
	}
}
int fibonacci_arr_2(int n)          //�������еݹ�
{
	if (n == 1 || n == 2)
		return 1;
	else return fibonacci_arr_2(n - 1) + fibonacci_arr_2(n-2);
}
#define level 4
int  is_triangle(int (*arrr)[level])         //�ǲ�������������ʽ
{
	for (int i = 1; i < level; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if  ( arrr[i][j] == 0)
				continue;
			else return -1;
		}
	}
	return 1;
}
void test0()
{
	int arr1[level][level] = {
		1,2,3,4,
		0,1,3,4,
	    0,0,1,4,
		0,0,0,4,
	};
	printf("%d", is_triangle(arr1));
}
int  test111()                                         //����������Ƿ������ҵģ� ��ȫ��ȣ�ÿ�ζ������ݼ�����һ������ ��<,=,>
{
	int k;
	int arr[50]={0};
	scanf("%d",&k);
	for (int i = 0; i < k; i++)
	{
		scanf("%d",arr+i);
    }
	if (arr[0] < arr[1])
	{
		for (int i = 1; i < k - 1; i++)
		{
			if (arr[i] < arr[i + 1])
				continue;
			else return -1;
		}
		return 1;
	}
	else if (arr[0] == arr[1])
	{
		for (int i = 1; i < k - 1; i++)
		{
			if (arr[i] == arr[i + 1])
				continue;
			else return -1;
		}
		return 1;
	}
	else 
	{
		for (int i = 1; i < k - 1; i++)
		{
			if (arr[i] > arr[i + 1])
				continue;
			else return -1;
		}
		return 1;
	}
}
int test112()            ////����������Ƿ����򣨻����ҵģ� �����ע˳�򣬰���<=�����
{
	int k;
	int arr[50] = { 0 };
	scanf("%d", &k);

		for (int i = 0; i < k; i++)
		{
			scanf("%d", arr + i);
		}

		int flag1 = 0, flag2 = 0;
		for (int i = 0; i < k - 1; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				flag1 = 1;
			}
			else if (arr[i] > arr[i + 1])
			{
				flag2 = 1;
			}
			else;
		}
		if (flag1 + flag2 == 2)
			printf("����\n");
		else printf("����\n");
}
int main()
{
	printf("%d",test112());
	return 0;
}