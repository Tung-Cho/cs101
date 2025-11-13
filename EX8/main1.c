#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    
    
    
    srand(1);
    int n;
    scanf("%d",&n);
    
    char buffer[1024]="========= lotto649 =========\n";
    FILE* fp;
    fp = fopen("lotto.txt","w+");
    fprintf(fp,"%s",buffer);
    
    time_t now;
    struct tm *local_time;
    char date_line[128]; // ?其??脣??澆??????銝?

    time(&now); // ?脣??嗅?????
    local_time = localtime(&now); // 頧??箸?唳???瑽?
    
    // ?澆???銝?(蝭??澆?: "November 13 2025\n")
    // %B = 摰??隞賢?蝔? %d = ?交?, %Y = ???詨僑隞?
    strftime(date_line, sizeof(date_line), "%B %d %Y", local_time); 
    fprintf(fp, "===== %s =====\n", date_line); // 撠?????交?撖怠瑼?
    
    for(int i=0;i<5;i++){
        int used[80];
        for(int i=0;i<79;i++){
            used[i]=0;
        }

        fprintf(fp,"%c%d%c:",'[',i+1,']');
        
        if(i+1<=n){
            int count=0;
            while(count<7){
                int tmp=rand()%69+1;
                if(used[tmp]==0){
                    used[tmp]=1;
                    fprintf(fp," %02d",tmp);
                    count++;
                }
            }
        }
        else{
            for(int i=0;i<7;i++)
                fprintf(fp," __");
        }
        
        fprintf(fp,"\n");
    }
    
    char new_content[] = "========= csie@CGU =========\n";
    snprintf(buffer, sizeof(buffer), "%s", new_content); 
    fprintf(fp,"%s",buffer); 
    
    
    fclose(fp);
    
    
    //???啁?
    
    printf("隢撓?乩葉??蝣潔??? ");
    int win_num[3];
    scanf("%d %d %d",&win_num[0],&win_num[1],&win_num[2]);
    printf("頛詨銝剔??Ⅳ?? %02d %02d %02d\n",win_num[0],win_num[1],win_num[2]);
    printf("隞乩??箔葉?蔗??\n");
    
    FILE* read_fp;
    read_fp = fopen("lotto.txt","r");
    
    char line_buffer[256];
    char date_str[256];
    
    strcpy(date_str,date_line);
    
    while(fgets(line_buffer, sizeof(line_buffer), read_fp) != NULL) {
        
        if (line_buffer[0] == '[') {
            int lotto_id;
            int ticket_nums[7];
            
            int parsed_count = sscanf(line_buffer, "[%d]: %d %d %d %d %d %d %d",
                                      &lotto_id, &ticket_nums[0], &ticket_nums[1],
                                      &ticket_nums[2], &ticket_nums[3], &ticket_nums[4],
                                      &ticket_nums[5], &ticket_nums[6]);
            
            if (parsed_count == 8) { 
                int match_count = 0;
                
                for (int i = 0; i < 7; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (ticket_nums[i] == win_num[j]) {
                            match_count++;
                        }
                    }
                }
                
                if (match_count > 0) {
                    line_buffer[strcspn(line_buffer, "\n")] = 0; 
                    printf("?桀??: %s: %s\n", date_str, line_buffer);
                }
            }
        }
    }
    
    
    
    
    
    
    return 0;
}
