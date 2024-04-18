#include <stdio.h>
#include <string.h>
#include <math.h>
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
int S_to_D(char *arr)
{
	char* p,*p2 ;
	p = p2 = arr;
	int n = 0;
	int rel = 0;
	while (*p != '\0')
	{
		p++;
		n++;
    }
	while(n!=0)
		rel += (*p2++ - '0') * pow(10, --n);

	return rel;
}
int main()
{
	printf("%d", S_to_D("1234"));
	return 0;
}