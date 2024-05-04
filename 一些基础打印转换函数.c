#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
void printf_DToS(int d)
{
     do
     {
		putchar(d%10+'0');
		d /= 10;
	 } while (d);
}

void printf_S(char *a)
{
	char* p=a;
	putchar(*p++);
	if (*p != '\0')
	{
		printf_S(p);
	}
}
int my_atoi(const char* str)
{
	assert(str);
	char* p, * p2, * p3;
	p = p2 = p3 = str;
	int n = 0;
	long long rel = 0;

	while (*p == ' ')
	{
		p++;
		p2++;
	}
	while (*p2 == '-')
	{
		p++;
		p3 = p2;
		p2++;
	}
	while (*p != '\0' && *p >= '0' && *p <= '9')
	{
		p++;
		n++;
	}
	while (n != 0)
	{
		rel += (*p2++ - '0') * pow(10, --n);
		if (rel > INT_MAX)
			return -1;
	}
	if (*p3 == '-')
		rel *= -1;
	return rel;
}
int main()
{
	printf("%d", S_to_D("1234"));
	return 0;
}