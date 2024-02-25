#include <stdio.h>
#include<time.h>
int adjust(*arr, int size)
{
	while(left<right)
	{
	int left = 0;
	int right = size - 1;
	while (arr[left] % 2 == 1&& left < right)     //找一个偶数
		left++;
	while (arr[right] % 2 == 0&& left < right)    //找一个奇数
		righ--;
	int t = arr[right];
	arr[right] = arr[left];
	arr[left] = t;
    }
}
int main()
{
	int a[] = { 3,2,5,7};

	int size = sizeof(a) / sizeof(a[0]);
	adjust(a, size);

	for (int i = 0; i < sizeof(a) / sizeof(a[1]); i++)
		printf("%d ", a[i]);
	return 0;
}