#pragma execution_character_set("utf-8")  
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <math.h>
#include <assert.h>
void replaceSpace(char* str,int length)
{
	char* p = str,*p1=str;
	
	int space_count = 0;
	while (*p!='\0')
	{
		if (*p == ' ')
		{
			space_count++;
		}
		p++;
	}
	int end1 = length - 1;
	int end2 = length - 1 + 2 * space_count;
	while (end1!=end2)
	{
		if (p1[end1] == ' ')
		{
			p1[end2--] = '0';
			p1[end2--] = '2';
			p1[end2--] = '%';
			end1--;
		}
		else
		{
			p1[end2--] = p1[end1--];
		}
	}
}
char strr[50]="a b c d  e";
int main()
{
	replaceSpace(strr, strlen(strr));
	printf("%s", strr);
	return 0;
}