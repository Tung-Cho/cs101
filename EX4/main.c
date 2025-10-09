#include <stdio.h>

int main()
{
    FILE*fp;
    int a[] = {0,1,2};
    char b[] = "ABC";
    float c[] = {1.1,1.2,1.3};
    int ra[3];
    char rb[3];
    float rc[3];
    
    
    
    fp = fopen("cj.bin","wb+");
    fwrite(a,sizeof(a),1,fp);
    fwrite(b,sizeof(b),1,fp);
    fwrite(c,sizeof(c),1,fp);
    fseek(fp,0,SEEK_SET);
    fread(ra,sizeof(ra),1,fp);
    
    fseek(fp,sizeof(a),SEEK_SET);
    fread(rb,sizeof(rb),1,fp);
   
    fseek(fp,sizeof(a)+sizeof(b),SEEK_SET);
    fread(rc,sizeof(rc),1,fp);
    
    for(int i = 0; i < 3; ++i){
        printf("%d",ra[i]);
    }
    for(int i = 0; i < 3; ++i){
        printf("%c",rb[i]);
    }
    for(int i = 0; i < 3; ++i){
        printf("%f",rc[i]);
    }
}
