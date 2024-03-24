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
		while (*s1 != *s2 && *s1 != '\0')  //str1���ҵ�str2��ͷ
		{
			s1++;
		}
		p = s1;          //p��s1��ͷ���λ�ã�������
		while (*s1 == *s2&&*s1!='\0' && *s2 != '\0')   //�����˫����ַ�ͼӣ�ֱ�����ȣ����str2��б����˵���ҵ�
		{
			s1++; s2++;                         //��Ȼ������'\0'������++��ͳ�'\0'��
		}
		if (*s2 == '\0')          //˵��str1���к�str2��һ�²���
			return p;
		else                //s2ָ��str2��ͷ
			s2 = str2;
		if (*s1 == '\0')        //str1���ҵ����Ҳû�к�str2һ����
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
	if (dest < src)                   //Ŀ�ĵ��ں��棬��ǰ���󿽱�
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