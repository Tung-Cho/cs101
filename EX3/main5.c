#include <stdio.h>

int main()
{
    int i = 0 ;
    scanf("%d",&i);
    if(i%400 == 0 || (i%4 == 0 && i%100 != 0)){
        printf("閏年");
    }else{
        printf("不是閏年");
    }

    return 0;
}
