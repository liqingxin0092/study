#include <stdio.h>
#include<time.h>
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 ,11,12 };
	for (int i = 0; i < sizeof(a) / sizeof(a[1]); i++)
	{
		if (a[i] % 2 == 0)
		{
			int t = a[i];
			for (int j = sizeof(a) / sizeof(a[0]) - 1; j >= 0; j--)
			{
				if (a[j] % 2 == 1)
				{
					a[i] = a[j];
					a[j] = t;
					break;
				}
			}
		}
		if (i > (sizeof(a) / sizeof(a[1]) - 3) / 2)
			break;
	}
	for (int i = 0; i < sizeof(a) / sizeof(a[1]); i++)
		printf("%d ", a[i]);
	return 0;
}