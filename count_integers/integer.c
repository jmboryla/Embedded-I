#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *infile;
    int inValue;

    infile=fopen ("integers.txt","r");
    if (infile== NULL)
    {
        puts("ERROR");
    }

    unsigned int count=0;

    while (fscanf(infile,"%d", &inValue)>0)
    {
        count++;
    }

    printf("integer count is %d\n", count);

    unsigned int i=0;
    int array[count];
    while (i<count)
    {
        fscanf(infile,"%d", &array[i]);
        printf("%5d",array[i]);
        ++i;
    }

    return 0;
}
