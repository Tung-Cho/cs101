#include <stdio.h>

int main()
{
    int i = 0;
    scanf("%d",&i);
    if(i & (i-1))printf("false");
    else printf("true");
    return 0;
}
