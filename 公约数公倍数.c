#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test()
{
	int m, n,t,max,min,t_m,t_n;
	scanf("%d %d", &m,&n);
	t_m = m;
	t_n = n;

	!(m < n) || (t = m, m = n, n = t);  //如果m<n,就交换。

	do {
		t = n;
		n = m % n;
		m = t;
	}
		while (n);
		
	max = m;
	min = t_m * t_n / max;
	printf("%d",max+min);

}
int main()
{
	test();
	return 0;
}