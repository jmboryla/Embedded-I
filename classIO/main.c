#include <stdio.h>
#include <stdlib.h>

int main()
{
    //create a file stream pointer
    FILE *fp,*outFP;

    char word[50];

    const char* filename="integers.txt";

    //open file name student.txt
    fp = fopen("student.txt","r");

    if (fp == NULL)
    {
        fprintf(stderr, "failed to open %s\n",filename);
        exit(1);
    }
    //open file named ouput.txt for output
    outFP=fopen("example.txt","w");

    if ((outFP)==(NULL))
    {
        puts("Failed to open example.txt");
    }
    while ( fscanf(fp,"d",&inValue) >= 0)
    {
        fprintf(stdout,"%d\n",&inValue);

    }

    fclose(fp);
    fclose(outFP);
    return 0;
}
