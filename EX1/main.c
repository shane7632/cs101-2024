/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


void print_spaces(int rows,int r){
    for(int space=1;space<=rows-r;space++){
        printf(" ");
    }
}



void print_pascal_number(int rows,int r){
 int coef=r;
for(int number=1;number<=r+1;number++){
    printf("%d ",r+1);
}
    
}

int main()
{
 int rows=6;
 for(int r=0;r<rows;r++){
     
     print_spaces(rows,r);
     
    print_pascal_number(rows,r);
     printf("\n");
 }

    return 0;
}
