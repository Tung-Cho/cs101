#include <stdio.h>

int main()
{
    for(int i = 1; i <= 6; ++i){
        for(int j = 6; j >= 1; --j){
            if(j-i > 0) printf(" ");
            else if(j-i <= 0)printf("%d " ,i);
        }
        printf("\n");
    }
}
