#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

typedef struct{
    int receipt_id;
    int receipt_price;
    char random_time[32];
    int lotto_set[5][7];
} lotto_record_t;

int random_number(){
    return rand()%69+1;
}

int* lotto_number_each(){
    static int lotto_list[7];
    int isrepeat[70]={0};
    
    for(int i=0;i<7;i++){
        int b=random_number();
        while(isrepeat[b]==1){
            b=random_number();
        }
        isrepeat[b]=1;
        lotto_list[i]=b;
    }
    
    return lotto_list;
}

void lotto_number(int a[5][7], int n){
    for(int i=0;i<n;i++){
        int* numbers = lotto_number_each();
        for (int j = 0; j < 7; j++) {
            a[i][j] = numbers[j];
        }
    }
}

void create_lotto(lotto_record_t* p, int num, int howmany){
    p->receipt_id = num;
    p->receipt_price = 100 * howmany;
    
    time_t t = time(NULL);
    struct tm *tm_now = localtime(&t);
     strftime(p->random_time, sizeof(p->random_time), "%a %b %e %T %Y", tm_now);
    
    lotto_number(p->lotto_set, howmany);
}

void write_lotto_to_file(lotto_record_t* p, const char* filename,int num) {
    FILE *file = fopen(filename, "w");
   
    fprintf(file, "========= lotto649 =========\n");
    fprintf(file, "========+ No.0000%d +========\n",num);
   
    fprintf(file, "= %s =\n", p->random_time);
   
    for (int i = 0; i < 5; i++) {
        fprintf(file, "[%d]: ", i + 1);
        for (int j = 0; j < 7; j++) {
            if(p->lotto_set[i][j]<10&&p->lotto_set[i][j]>0)
             fprintf(file, "0%d ", p->lotto_set[i][j]);
            else if( p->lotto_set[i][j]>0)
            fprintf(file, "%d ", p->lotto_set[i][j]);
            else
             fprintf(file, "__ ");
        }
        fprintf(file, "\n");
    }
     fprintf(file, "========= csie@CGU =========\n");
    fclose(file);
}

void write_lotto_to_bin(lotto_record_t* p, const char* filename) {
    FILE *file = fopen(filename, "ab");
    if (file != NULL) {
        fwrite(p, sizeof(lotto_record_t), 1, file);
        fclose(file);
    } else {
        printf("Unable to open file %s\n", filename);
    }
}

void read_lotto_from_bin(const char* filename,int a1,int a2,int a3) {
    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        lotto_record_t lotto;
        while (fread(&lotto, sizeof(lotto_record_t), 1, file)) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 7; j++) {
                    if (lotto.lotto_set[i][j] == a1 || lotto.lotto_set[i][j] == a2 || lotto.lotto_set[i][j] == a3) {
                        printf("彩券 No.%d\n", lotto.receipt_id);
                        printf("售出時間: %s\n", lotto.random_time);
                        printf("號碼:");
                        for (int k = 0; k < 7; k++) {
                            printf("%d ", lotto.lotto_set[i][k]);
                        }
                        printf("\n");
                        break;
                    }
                }
            }
        }
        fclose(file);
    } else {
        printf("Unable to open file %s\n", filename);
    }
}

int main()
{
    srand(1);
    lotto_record_t lotto[20];
    lotto_record_t lottoback[20];
    int lotto_amount = 1;
    
    for(int i=1;i<20;i++){
        printf("請問你要買幾組：");
        scanf("%d", &lotto_amount);
    
        if(lotto_amount!=0){
            char filename[20];
            sprintf(filename, "lotto[000%d].txt", i);
            create_lotto(&lotto[1], i, lotto_amount);
            write_lotto_to_file(&lotto[1], filename,i);
            write_lotto_to_bin(&lotto[1], "record.bin");
        }
        
        
        else i+=100;
    }
    int a1,a2,a3;
    if(lotto_amount==0){
        printf("請輸入中獎號碼");
         scanf("%d %d %d", &a1,&a2,&a3);
    }
    
    
    
    read_lotto_from_bin("record.bin",a1,a2,a3);
    
    return 0;
}