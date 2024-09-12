#include <stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int k;
    int mx=1;
    int mi=1;
    printf("상품 종류 입력:");
    scanf("%d",&n);
    int num1[n];
    int num2[n];
    float sum1,sum2;
    float pan;
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
    printf("재고 수량:");
    for(int i=1;i<=n;i++)
    {
        printf("%2d",num1[i]-num2[i]);
    }
    for(int i=1;i<=n;i++)
    {
        sum1+=num2[i];
        sum2+=num1[i];
    }
    pan=sum1/sum2*100.0;
    printf("총 판매량:%f (판매율:%f%)\n",sum1,pan);
    for(int i=1;i<=n;i++)
    {
        if(num2[i]>num2[mx])
        mx=i;
        if(num2[i]<num2[mi])
        mi=i;
    }
    printf("가장 많이 판매된 상품:ID %d 판매량%d\n",mx,num2[mx]);
    printf("가장 적게 판매된 상품:ID %d 판매량%d\n",mi,num2[mi]);
    for(int i=1;i<=n;i++)
    {
        if(num1[i]-num2[i]<=2)
        printf("상품ID %d:재고부족(%d)\n",i,num1[i]-num2[i]);
    }
    
    return 0;
}
