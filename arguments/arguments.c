#include <stdio.h>

const char options[7][16]= {"-all","-min","-max","-mean","-median","-stdev","-var"};

typedef enum {ALL, MIN, MAX, MEAN, MEDIAN, STDEV, VAR, UNKNOWN}runState;

int main (int argc, char **argv){

    int i;
    for (i=0; i<argc ; i++)
    {
        fprintf(stdout, "argv[%d]: %s",i,argv[i]);
    }
}
