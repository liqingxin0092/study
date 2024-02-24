#include <stdio.h>
#include<time.h>
int main()
{
	time_t count;
	struct tm *date;
	char* time_str;

	time(&count);
	date = gmtime(&count);
	printf("%d\n", count);
	printf("%d\n", date->tm_hour);

	date = localtime(&count);
	printf("%d\n", date->tm_hour);

	char a[20];
	strftime(a,20,"%H:%M:%S", date);
	printf(a);

	return 0;
}