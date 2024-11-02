#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int getline(char* line)
{
	int ch;
	int i = 0;
	while ((ch = getchar()) != '\n') line[i++] = ch;
	line[i] = '\0';
	return i;
}
int main()
{
	char input[100];
	FILE* fp;

	if ((fp = fopen("output.txt", "w")) == NULL) {
		printf("ERROR...");
		return 0;
	}
	for (int i = 0; i < 5; i++)
	{
		getline(input);
		fputs(input, fp);
		fputs("\n", fp);
	}

	fclose(fp);
	return 0;

}