/*Class:Elec 1520
*Assignment:Pointers 1
*Program Author:Jonathan Boryla
*Date:October 16, 2017
*Tested on
*    C Environment:CodeBlocks
*    Operating System:Windows 10
*Description:This program displays the byte size of different variable types of pointers
*/


#include <stdio.h>

int main ()
{
    //initializing pointers of different types
    char *pchar;
    short *pshort;
    int *pint;
    long *plong;
    float *pfloat;
    double *pdouble;

    //displaying the size of each pointer type using sizeof function
    printf ("size of (char*): %u bytes\n",sizeof(pchar));
    printf ("size of (short*): %u bytes\n",sizeof(pshort));
    printf ("size of (int*): %u bytes\n",sizeof(pint));
    printf ("size of (long*): %u bytes\n",sizeof(plong));
    printf ("size of (float*): %u bytes\n",sizeof(pfloat));
    printf ("size of (double*): %u bytes\n",sizeof(pdouble));
    return 0;
}

