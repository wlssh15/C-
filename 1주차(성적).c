#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
int main()
{
	int number[SIZE];
	int total=0;
	int max, min;
	float avg=0.0;
	
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		number[i] = rand() % 101;
		total += number[i];
	}
	
	for (int i = 0; i < SIZE; i++)
	{
		printf("%3d\t", number[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	avg = (float)total / SIZE;
	max = 0;
	min = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (number[max] < number[i]) max =i;
		if (number[min] > number[i]) min = i;
		
	}
			
	printf("ЦђБе=%f\n", avg);
	printf("max=%d min=%d", number[max],number[min]);
	return 0;
}