#pragma execution_character_set("utf-8")  
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRANSMIT(n)     ((((n)&0xaaaaaaaa)>>1)+(((n)&0x55555555)<<1)) //һ�����Ķ�����λ��ż��λ����

//һ��˼·����������Ĺ����ǣ���һ�������е�����ֻ������һ�ε�����������������2�Σ�
void find(int arr[], int size, int* e1,int * e2)
{
	int i = 0;
	int rel = 0;
	//1.���
	for (i = 0; i < size; i++)
	{
		rel ^= arr[i];   //������ʵ����������ֻ����һ�ε��������
	}
	//2.����rel�Ķ����������ұߵĵĵڼ�λ��1       ��Ŀ�����ҳ��������������ƴӵڼ�λ��ʼ��ͬ��
	// ��ԭ�����е�������λΪһ�͸�λΪ��ֳ�����    ���磺1��1���ֵ����λΪ1���飬2��2���ֵ����λΪ0���飬�Դ�����
	int pos = 0;
	for (pos = 0; pos < 32; pos++)
	{
		if (((rel >> pos) & 1) == 1)
		{
			break;
		}
	}
	//3.��������
	for (i = 0; i < size; i++)        
	{
		if (((arr[i] >> pos) & 1) == 1)   //�Ѹ�λΪһ�͸�λ��Ϊһ������Ϊ����
		{
			*e1 ^= arr[i];     //һ�������Ͷ���������ֻʣ�µ���
		}
		else
		{
			*e2 ^= arr[i];
		}
	}
}
int main()
{
	int arr[] = {1,2,3,4,5,1,2,3,4,6};
	int size = sizeof(arr) / sizeof(arr[0]);
	int dog1 = 0, dog2 = 0;
	find(arr, size, &dog1, &dog2);
	printf("%d %d ",dog1 ,dog2 );
	return 0;
}