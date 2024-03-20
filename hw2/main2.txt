
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputFile, *outputFile;
    char character;
    
     inputFile = fopen("main.c", "r");
     
    outputFile = fopen("main2.txt", "w");
    
    while ((character = fgetc(inputFile)) != EOF) {
        fputc(character, outputFile);
    }
    
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}
