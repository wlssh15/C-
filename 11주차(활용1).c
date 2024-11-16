#include<stdio.h>
#include<stdlib.h>
typedef struct point {
	int x;
	int y;
}POINT;
int inputMenu() {
	int input;
	printf("메뉴입력(1.구조체 만들기,2.구조체 출력하기,-1.종료)");
	scanf_s("%d", &input);
	return input;
}
int main()
{
	int menu;
	do {
		menu = inputMenu();
		printf("%d\n", menu);
		if (menu == 1) {
			//구조체 만들기
		}
		else if (menu == 2) {
			//구조체 출력하기
		}
		else if (menu == -1)
			printf("프로그램 종료");
	} while (menu > 0);

	return 0;
}
//POINT* point;
//int count;
//scanf_s("%d", &count);
//
//point = (POINT*)malloc(sizeof(POINT) * count);
//
//for (int i = 0; i < count; i++) {
//	point[i].x = rand() % 100;
//	point[i].y = rand() % 100;
//}
//for (int i = 0; i < count; i++) {
//	printf("x=%d y=%d\n", point[i].x, point[i].y);
//}
//free(point);
