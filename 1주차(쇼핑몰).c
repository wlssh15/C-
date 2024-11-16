#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int k;
    printf("상품 종류 입력:");
    scanf("%d",&n);
    int num1[n];
    int num2[n];
     printf("입고수량 입력:");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num1[i]);
    }
    
    printf("판매수량 입력:");
     for(int i=1;i<=n;i++)
     {
         scanf("%d",&num2[i]);
     }
        
    printf("상품id입력:");
    scanf("%d",&k);
    
    printf("%d의 재고 수량:%d\n",k,num1[k]-num2[k]);
    for(int i=1;i<=n;i++)
    {
        printf("%d의 재고 수량:%d\n",i,num1[i]-num2[i]);
    }
    return 0;
}
