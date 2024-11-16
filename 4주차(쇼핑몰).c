#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define SIZE 5

void dlqrh(int* array, int size)
{
    int n;
    int k;
    printf("입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("입고수량 입력:");
        for (int i = 1; i <= size; i++)
        {
            scanf("%d", &array[i]);
        }
    }
    else if (n == 2)
    {
        printf("상품ID:");
        scanf("%d", &k);
        printf("입고수량:");
        scanf("%d", &array[k]);
    }
}
void vksao(int* array, int size)
{
    int n;
    int k;
    printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("판매수량 입력:");
        for (int i = 1; i <= size; i++)
        {
            scanf("%d", &array[i]);
        }
    }
    else if (n == 2)
    {
        printf("상품ID:");
        scanf("%d", &k);
        printf("판매수량:");
        scanf("%d", &array[k]);
    }
}
void tkavnd(int* b, int* c, char name[SIZE][100], int size)
{
    float sale = 0, e = 0;
    int n = 0, m = 0;

    printf("재고 수량:\n");
    for (int i = 0; i < size; i++) {
        printf("상품명 %s: %d개 남음\n", name[i], b[i] - c[i]);
    }

    for (int i = 0; i < size; i++) {
        sale += c[i];
        e += b[i];
    }

    double f = (sale / e) * 100;
    printf("총 판매량 %.0f (판매율 %.2lf%%)\n", sale, f);

    for (int i = 0; i < size; i++) {
        if (c[i] > c[n]) n = i;
        if (c[i] < c[m]) m = i;
    }

    printf("가장 많이 팔린 상품: %s, 판매량: %d\n", name[n], c[n]);
    printf("가장 적게 팔린 상품: %s, 판매량: %d\n", name[m], c[m]);

    for (int i = 0; i < size; i++) {
        if (b[i] - c[i] <= 2) {
            printf("상품명 %s: 재고부족 (%d개 남음)\n", name[i], b[i] - c[i]);
        }
    }
}
void tkdvnaaud(char name[SIZE][100], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ID %d 상품명:",i+1);
        scanf("%s", name[i]);
    }
}
int main()
{
    int n;
    int num1[SIZE] = { 0 };
    int num2[SIZE] = { 0 };
    char name[SIZE][100];
    while (1)
    {
        printf("원하는 메뉴를 선택하세요 (1.입고, 2.판매, 3.상품현황, 4.상품명 입력, 5.종료): ");
        scanf("%d", &n);
        if (n == 1)
            dlqrh(num1, SIZE);
        else if (n == 2)
            vksao(num2, SIZE);
        else if (n == 3)
            tkavnd(num1, num2, name, SIZE);
        else if (n == 4)
            tkdvnaaud(name, SIZE);
        else if (n == 5)
            break;
    }

    return 0;
}
