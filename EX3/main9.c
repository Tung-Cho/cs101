#include <stdio.h>

int main()
{
    int x = 0, y = 0, z = 0;
    scanf("%d %d %d",&x,&y,&z);
    if(x < 0){
        int sum = (x*-1)*100 + y*10 + z;
        printf("%d",sum*-1);
    }else{
        printf("%d",x*100 + y*10 + z);
    }
    
    return 0;
}
