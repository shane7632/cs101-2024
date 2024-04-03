#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int receipt_id;
    int receipt_price;
    int receipt_time[32];
    int lotto_set[5][7];
} lotto_record_t;

int main() {
    int n;
    printf("請問你要買幾組樂透彩:");
    scanf("%d", &n);
    
   
    
    lotto_record_t number[n]; 
    
    srand(1); 
    
    for (int i = 0; i < n; i++) {
        FILE *file;
        char filename[20];
        sprintf(filename, "lotto%d.txt", i + 1);
        file = fopen(filename, "w");
     fprintf(file, "lotto649");
     fprintf(file, "=======+No.00%d+=======",i);
      fprintf(file, "=======+No.00%d+=======",i);
        
        for (int j = 0; j < 5; j++) {
            int isrepeat[70] = {0}; 
            fprintf(file, "[%d]: ", j + 1);
            for (int k = 0; k < 7; k++) {
                number[i].lotto_set[j][k] = rand() % 69 + 1;
                
                while (isrepeat[number[i].lotto_set[j][k]] == 1) {
                    number[i].lotto_set[j][k] = rand() % 69 + 1;
                }
                isrepeat[number[i].lotto_set[j][k]] = 1;
                fprintf(file, "%d ", number[i].lotto_set[j][k]);
            }
            fprintf(file, "\n");
        }
        
        fclose(file);
    }
    
    return 0;
}
