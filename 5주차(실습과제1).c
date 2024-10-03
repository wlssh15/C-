#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char src[100];
	char dest[100];
	int length,result;
	gets(src);
	gets(dest);
	result= strcmp(src, dest);
	printf("result = %d\n", result);
	/*length = strlen(src);
	printf("length of src = %d\n", length);
	strcpy(dest, src);
	printf("src = %s  dest = %s\n",src, dest);
	strcat(dest, src);
	printf("src = %s, dest = %s\n", src, dest);*/
	

	return 0;
}
