#include<stdio.h>

int main()
{
	int ch;
	char message[100];
	int i = 0;

	ch = getchar();
	while ((ch = getchar()) != '\n')
	{
		message[i++] = ch;
	}
	message[i] = '\0';
	printf("%s", message);
	return 0;
}
