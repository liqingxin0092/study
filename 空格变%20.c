#pragma execution_character_set("utf-8")  
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include <assert.h>
void replaceSpace(char* str,int length)
{
	char* p = str;
	char* p1 = str;
	int n=0;
	int i,nn=0;
	while (*p)
	{
		while (*p != ' ')
		{
			p++;
			n++;
			if (!*p)
				return;
		}
		for (i = length; i >=n+nn; i--) //这里+nn是试出来的
		{
			p1[i + 2] = p1[i];
		}
		p[0] = '%';
		p[1] = '2';
		p[2] = '0';
		length += 2;
		p ++;
		nn++;
	}

}
char strr[50]="hello world i am lihua ni hao";
int main()
{
	replaceSpace(strr, strlen(strr));
	printf("%s", strr);
	return 0;
}