#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10
#define HIGH 100
#define LOW 0

int main(void)
{
    srand(time(NULL));
    int randomArray[ARRAY_SIZE]={0};
    int i, j;
    int dummy;

    for (i=0;i<ARRAY_SIZE;++i)
    {
        randomArray[i]=(rand()%(HIGH-LOW+1))+LOW;
    }

    printf("Original Array\n\n");

    for (i=0;i<ARRAY_SIZE;++i)
    {
        printf("%4d",randomArray[i]);
    }
    for (j=0;j<ARRAY_SIZE-1;++j)
    {

        for (i= j+1;i<ARRAY_SIZE;++i)

        {
            if(randomArray[j]>randomArray[i])
            {
                //switch places
                dummy=randomArray[j];
                randomArray[j]=randomArray[i];
                randomArray[i]=dummy;
            }
        }

    }
    printf("\n\nSorted Array\n\n");
    for(i=0;i<ARRAY_SIZE;++i)
    {
        printf("%4d",randomArray[i]);
    }
    puts("");
    return 0;
}
