#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char line[100]; 
    int lineNumber = 0;

   
    inputFile = fopen("main.c", "r");
   
   
    outputFile = fopen("main3.txt", "w");
    

   
    while (fgets(line, sizeof(line), inputFile)) {
        lineNumber++;

       
        if (strstr(line, "int main()")) {
           
            fprintf(outputFile, "%d\n", lineNumber);
           break;
        }
    }

    
    fclose(inputFile);
    fclose(outputFile);

    

    return 0;
}
