/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    FILE* fp;
    int a[3]={0,1,2};
    int ar[3];
    char b[3]="ABC";
    char br[3];
    float c[3]={1.1,1.2,1.3};
    float cr[3];
    
    fp=fopen("a.bin","wb+");
    fwrite(a,sizeof(a),1,fp);
    fwrite(b,sizeof(b),1,fp);
    fwrite(c,sizeof(c),1,fp);
    fseek(fp,0,SEEK_SET);
    fread(ar,sizeof(ar),1,fp);
    fread(br,sizeof(br),1,fp);
    fread(cr,sizeof(cr),1,fp);
    
    for(int i=0;i<3;i++){
        printf("%d\t",ar[i]);
        
    }
    printf("%c",'\n');
    for(int i=0;i<3;i++){
        printf("%c\t",br[i]);
    }
    printf("%c",'\n');
    for(int i=0;i<3;i++){
        printf("%f\t",cr[i]);
    }

    return 0;
}
