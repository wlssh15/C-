main.c
#include<stdio.h>
#include"calcul.h"

int main()
{
	printf("%d\n", add(10, 20));
	printf("%d\n", sub(10, 20));
	printf("%d\n", multi(10, 20));
	printf("%d\n", printAdd(10, 20));
	return 0;
}

calcul.h
#ifndef _CALCULATOR_H
#define _CALCULATOR_H
int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int multi(int a, int b) {
	return a * b;
}
int printAdd(int a, int b) {
	int sum = 0;
	for (int i = 0; i < b; i++) {
		sum += i;
	}
	return sum;
}
#endif
  
