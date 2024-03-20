/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int x;
    int num=1;
    int randnumber;
    FILE *outputFile;
    
    outputFile = fopen("lotto.txt", "w");
    printf("歡迎光臨長庚樂透彩購買機台\n請問您要買幾組樂透彩:");
    scanf("%d",&x);
     printf("已為您購買的%d組樂透組合輸出至 lotto.txt",x);
    srand(1);
    
    
    int number[100];
    number[5*x-1]=0;
    int value;
    int count=1;
    number[0]=rand()%69;
    for(int i=1;i<100;i++){
        value=rand()%69;
        int isrepeat=0;
        for(int j=0;j<count;j++){
            if(value==number[j]){
               isrepeat=1;
            }
        }
        
        if(isrepeat==0){
            number[count++]=value;
        }
        
        if(number[x*7-1]!=0)
        break;
        
    }
    
    
    
   
    
   fprintf(outputFile, "========= lotto649 =========\n");

    time_t currentTime;
    struct tm *localTime;
    time(&currentTime);
    localTime = localtime(&currentTime);
    fprintf(outputFile, "=%s", asctime(localTime));
    for(int i=0;i<x*7;i++){
         if(i%7==0){
           fprintf(outputFile, "[");
            fprintf(outputFile, "%d", num++);
            fprintf(outputFile, "]: ");
        }
         if (number[i] < 10) {
            fprintf(outputFile, "0%d ", number[i]);
        } else {
            fprintf(outputFile, "%d ", number[i]);
        }
        
          if(i%7==6){
            fprintf(outputFile, "\n");
        }
        
    }
    
    for(int i=0;i<35-(x*7);i++){
        if(i%7==0){
           fprintf(outputFile, "[");
            fprintf(outputFile, "%d", num++);
            fprintf(outputFile, "]: ");
        }
        
        fprintf(outputFile, "__ ");
        if(i%7==6){
            fprintf(outputFile, "\n");
        }
    }
    
   fprintf(outputFile, "========= csie@CGU =========\n");
    
    fclose(outputFile);

    return 0;
}
