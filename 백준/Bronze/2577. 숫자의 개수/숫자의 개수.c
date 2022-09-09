#include <stdio.h>

int main(){
    int n1, n2, n3,i;
    int mul, remain;
    int nums[10]={0,};
    scanf("%d %d %d",&n1,&n2,&n3);
    mul = n1*n2*n3;
    
    while(mul>0){
        remain = mul % 10;
        mul/=10;
        for(i=0;i<10;i++)
            if(i==remain) nums[remain]++;
    }
    for(i=0;i<10;i++)
        printf("%d\n", nums[i]);
    return 0;
}