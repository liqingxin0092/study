#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <ctype.h>
char* my_strcpy(char* dest, const char* src)
{
	char* p = dest;
	assert(dest&&src);
	while (*p++= *src++);
	return dest;
}
char* my_strcat(char* dest, const char* src)
{
	char* p = dest;
	assert(dest && src);
	while (*dest != '\0')
		dest++;
	while (*dest++ = *src++);
	return dest;
}
char my_strcmp(const char *a,const char* b)
{
	while (*a == *b)
	{
		if (*a == '\0')
			return 0;
		a++, b++;
	}
	return (*a - *b);
}
const char* my_strstr(const char* str1, const char* str2)
{
	assert(str1&&str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (1)
	{
		while (*s1 != *s2 && *s1 != '\0')  //str1中找到str2开头
		{
			s1++;
		}
		p = s1;          //p记s1开头这个位置，待返回
		while (*s1 == *s2&&*s1!='\0' && *s2 != '\0')   //如果等双方地址就加，直到不等，如果str2是斜杠零说明找到
		{
			s1++; s2++;                         //虽然不等于'\0'，可能++后就成'\0'了
		}
		if (*s2 == '\0')          //说明str1中有和str2中一致部分
			return p;
		else                //s2指向str2开头
			s2 = str2;
		if (*s1 == '\0')        //str1中找到最后也没有和str2一样的
			return NULL;
	}
}

void* my_memcpy(void* dest, const void* src, size_t num)
{
	assert(dest&&src);
	void* p = dest;
	for (size_t i = 0; i < num; i++)
	{
		*((char*)dest + i) = *((char*)src+i);
	}
	return dest;
}
void* my_memmove(void* dest, void* src, size_t num)
{
	assert(dest && src);
	void* p = dest;
	if (dest < src)                   //目的地在后面，从前往后拷贝
	{
		for (size_t i = 0; i < num; i++)
		{
			*((char*)dest + i) = *((char*)src + i);
		}
	}
	else
	{
		for (int j = num-1; j >= 0; j--)
		{
			*((char*)dest + j) = *((char*)src + j);
		}
	}
	return p;
}