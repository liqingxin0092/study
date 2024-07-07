#include <stdio.h>
#include<time.h>
int arr[100];
void adjust_arr(int *a,int *b ,int lenth1,int lenth2)
{
	int* pa = a;
	int* pb= b;
	static int na = 0;
	static int nb = 0;
	static int i;
	for(i=0;i< lenth1+ lenth2;i++)
	{
		if (*pa >= *pb)
		{
			arr[i] = *pb++;
			nb++;
			if (nb == lenth2 )
				goto exit_b;
		}
		else
		{
			arr[i] = *pa++;
			na++;
			if (na == lenth1 )
				goto exit_a;
		}
	}
	exit_b:
	while (na <= lenth1)
	{
		arr[++i] = *pa++;
		na++;
	}
		return;
	exit_a:
		while (nb <= lenth2)
		{
			arr[++i] = *pb++;
			nb++;
		}
		return;
}
int main()
{
	int a[] = { 1,2,3,5,7,9,12,13,13};
	int lenth1 = sizeof(a) / sizeof(a[1]);
	int b[] = {5,6,10,11,13,14};
	int lenth2 = sizeof(b) / sizeof(b[1]);

	adjust_arr(a, b, lenth1, lenth2);
	for (int i = 0; i < lenth1 + lenth2; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}