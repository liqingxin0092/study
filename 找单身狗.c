#pragma execution_character_set("utf-8")  
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRANSMIT(n)     ((((n)&0xaaaaaaaa)>>1)+(((n)&0x55555555)<<1)) //一个数的二进制位奇偶数位交换

//一种思路，这个函数的功能是，找一个数组中的两个只出现了一次的数（其他数出现了2次）
void find(int arr[], int size, int* e1,int * e2)
{
	int i = 0;
	int rel = 0;
	//1.异或
	for (i = 0; i < size; i++)
	{
		rel ^= arr[i];   //这个结果实际上是两个只出现一次的数的异或
	}
	//2.计算rel的二进制中最右边的的第几位是1       ，目的是找出两个单身狗二进制从第几位开始不同，
	// 把原数组中的数按该位为一和该位为零分成两组    例如：1和1被分到最低位为1的组，2和2被分到最低位为0的组，以此类推
	int pos = 0;
	for (pos = 0; pos < 32; pos++)
	{
		if (((rel >> pos) & 1) == 1)
		{
			break;
		}
	}
	//3.遍历数组
	for (i = 0; i < size; i++)        
	{
		if (((arr[i] >> pos) & 1) == 1)   //把该位为一和该位不为一的数分为两组
		{
			*e1 ^= arr[i];     //一个单身狗和多对情侣异或只剩下单身狗
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