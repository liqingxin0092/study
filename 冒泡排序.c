#include <stdio.h>
#include<time.h>
void bubble_sort(int *arr,int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (*(arr + j) > *(arr + j + 1))
			{
				int t = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = t;
			}
		}
	}

}
int main()
{
	int arr[] = { 5,4,3,2,1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}