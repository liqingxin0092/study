#include <stdio.h>
#include<time.h>
void adjust(int* arr, int size)
{
	int t[100];
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 1)
			t[j++] = arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
			t[j++] = arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = t[i];
	}
}
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };

	int size = sizeof(a) / sizeof(a[0]);
	adjust(a, size);

	for (int i = 0; i < sizeof(a) / sizeof(a[1]); i++)
		printf("%d ", a[i]);
	return 0;
}