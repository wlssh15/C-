#include <stdio.h>
#include<stdlib.h>
#define SIZE 5
void dlqrh(int* array,int size)
{
    int n;
    int k;
    printf("입고수량 입력 : 전체 상품 입고수량 입력 1, 개별 상품 입력 2를 선택");
    scanf("%d",&n);
    if(n==1)
    {
     printf("입고수량 입력:");
    for(int i=1;i<=size;i++)
    {
        scanf("%d",&array[i]);
    }
    }
    else if(n==2)
    {
        printf("상품ID:");
        scanf("%d",&k);
        printf("입고수량:");
        scanf("%d",&array[k]);
    }
}
void vksao(int* array,int size)
{
    int n;
    int k;
    printf("판매수량 입력 : 전체 상품 판매수량 입력 1, 개별 상품 입력 2를 선택");
    scanf("%d",&n);
    if(n==1)
    {
     printf("판매수량 입력:");
    for(int i=1;i<=size;i++)
    {
        scanf("%d",&array[i]);
    }
    }
    else if(n==2)
    {
        printf("상품ID:");
        scanf("%d",&k);
        printf("판매수량:");
        scanf("%d",&array[k]);
    }
}
void tkavnd(int* array1,int* array2,int size)
{
    int mx=1;
    int mi=1;
    float sum1,sum2;
    float pan;
    printf("재고 수량:");
    for(int i=1;i<=size;i++)
    {
        printf("%2d",array1[i]-array2[i]);
    }
    for(int i=1;i<=size;i++)
    {
        sum1+=array2[i];
        sum2+=array1[i];
    }
    pan=sum1/sum2*100.0;
    printf("총 판매량:%.0f (판매율:%.2f%)\n",sum1,pan);
    for(int i=1;i<=size;i++)
    {
        if(array2[i]>array2[mx])
        mx=i;
        if(array2[i]<array2[mi])
        mi=i;
    }
    printf("가장 많이 판매된 상품:ID %d 판매량%d\n",mx,array2[mx]);
    printf("가장 적게 판매된 상품:ID %d 판매량%d\n",mi,array2[mi]);
    for(int i=1;i<=size;i++)
    {
        if(array1[i]-array2[i]<=2)
        printf("상품ID %d:재고부족(%d)\n",i,array1[i]-array2[i]);
    }
}
int main()
{
    int n;
    int num1[SIZE];
    int num2[SIZE];
    while(1)
    {
    printf("원하는 메뉴를 선택하세요(1.입고,2.판매,3.상품현황,4.종료");
    scanf("%d",&n);
    if(n==1)
    dlqrh(num1,SIZE);
    else if(n==2)
   vksao(num2,SIZE);
    else if(n==3)
    tkavnd(num1,num2,SIZE);
    if(n==4)
    break;
    }
   
    return 0;
}
