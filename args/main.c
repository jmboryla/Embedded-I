#include <stdio.h> /*fprintf*/
#include <stdlib.h> /*exit*/
#include <string.h> /*strcmp atoi*/
#include <math.h>   /*pwr sqrt*/


#define NUM_OPTIONS 7 /*Macros*/

/*Function Prototypes*/
void extractIntegerData(int data[], int dataSize, char** argv,int startIndex,int stopIndex);
int findMin(int a[], int n);
int findMax(int a[], int n);
int findMed(int a[], int n);
double findMean(int a[], int n);
int findVar(int a[], int n, int mean);
double findStdev(int var);

/*Enumeration for program options*/
typedef enum {ALL,MIN,MAX,STDEV,VAR,MEAN,MEDIAN,UNKNOWN} runState;

/*Array to compare to user input. Array position matches enumeration*/
const char runOptions[NUM_OPTIONS][16]={"-all","-min","-max","-stdev","-var","-mean","-median"};

/*Function gets users option choice*/
runState extractOption(char *option)
{
    int i=0;   //initialize i
    while(i<NUM_OPTIONS)    //loops through number of options
    {
        if(strcmp(option,runOptions[i])==0) //string compare compares what the user entered to runOptions array
           {
               return i;    //returns position of selected option
           }
        ++i;    //increment i
    }
    return UNKNOWN; //if user input is not a valid option UNKNOWN is returned
}


int main (int argc,char **argv)
{
    //declares variables
    int dataSize= argc-2;
    int numberArray[dataSize];

    //minimum arguments
    if(argc<3){
        fprintf(stderr,"Minimum of three arguments required, usage:run.exe -option (signed integer list)\n"); //prints error statement to standard error stream
        exit(1); //exits program
    }

    runState state; //declares varible state or runState type

    extractIntegerData(numberArray, dataSize, argv ,2 ,argc);   //calls extract integer data function

    state = extractOption(argv[1]); //calls extractOption function and assigns return value to variable state
    switch(state)   //switch statement switches on state
    {
        case ALL:   //for case user enters all all functions are run and values are printed to the console
            fprintf(stdout,"\nMin:%-8d\n", findMin(numberArray,dataSize));
            fprintf(stdout,"\nMax:%-8d\n", findMax(numberArray,dataSize));
            fprintf(stdout,"\nMean:%-8.2f\n", findMean(numberArray,dataSize));
            fprintf(stdout,"\nMedian:%-8d\n", findMed(numberArray,dataSize));
            fprintf(stdout,"\nStandard Deviation:%-8.2f\n", findStdev(findVar(numberArray,dataSize,findMean(numberArray,dataSize))));
            fprintf(stdout,"\nVariance:%-8d\n", findVar(numberArray,dataSize,findMean(numberArray,dataSize)));
            break;

        case MIN:  //case user enters min
            fprintf(stdout,"\nMin:%-8d\n", findMin(numberArray,dataSize));  //findMin function is called and return value is printed
            break;

        case MAX: //case user enters max
            fprintf(stdout,"\nMax:%-8d\n", findMax(numberArray,dataSize));  //findMax is called and return value is printed
            break;

        case MEAN:  //case user enters mean
            fprintf(stdout,"\nMean:%-8.2f\n", findMean(numberArray,dataSize));  //findMean is called and return value is printed as a float
            break;

        case MEDIAN: //case user enters median
            fprintf(stdout,"\nMedian:%-8d\n", findMed(numberArray,dataSize)); //findMed is called and return value is printed
            break;

        case STDEV: //case user enters stdev
            //calls findStdev function passes findVar function and prints return value as a floating point number
            fprintf(stdout,"\nStandard Deviation:%-8f\n", findStdev(findVar(numberArray,dataSize,findMean(numberArray,dataSize))));
            break;

        case VAR:   //case user enters var
            fprintf(stdout,"\nVariance:%-8d\n", findVar(numberArray,dataSize,findMean(numberArray,dataSize))); //calls findVar function and prints return value
            break;

        case UNKNOWN:   //Case unknown is returned from extractOption function
            fprintf(stderr,"Valid option not entered"); //Error message if user does not enter valid option
            break;

        default:
            fprintf(stderr,"err, default label, line: %d",__LINE__);    //jf default is reached line where error occurred is printed

    }
    return 0;
}


//Function to extract user entered integers
void extractIntegerData(int data[], int dataSize, char** argv,int startIndex,int stopIndex)
{
    //initialize variables
    int i;
    int currentIndex;

    for (i=0, currentIndex=startIndex; i<dataSize&&currentIndex<stopIndex;++i,++currentIndex) //loops through entered integers
    {
        data[i]=atoi(argv[currentIndex]); //uses ascii to integer function to convert string to integer and saves it in array
    }
}

//Find minimum number entered
int findMin(int a[], int n)
{
    //initialize variables
    int i,j;
    for (i=0;i<n;++i)   //outer for loop for sorting
    {
        for(j=0;j<n;j++)    //inner for loop
        {
            if(a[j]>a[i])   //sorts low to high
            {
            //switch places
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            }
        }
    }
    return a[0]; // returns number in first position
}

//Find maximum number entered
int findMax(int a[], int n)
{
    //initialize varibles for loops
    int i,j;
    for (i=0;i<n;++i)   //outer loop for sorting
    {
        for(j=0;j<n;j++)    //inner loop for sorting
        {
            if(a[i]>a[j])   //sorts highest to lowest
            {
            //swaps variables places
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            }
        }
    }
    return a[0];    //returns value in first position
}

//Find the median of numbers entered
int findMed(int a[], int n)
{
    //variables for looping
    int i,j;
    for (i=0;i<n;++i)   //outer sorting loop
    {
        for(j=0;j<n;j++)    //inner sorting loop
        {
            if(a[j]>a[i])   //sorts lowest to highest
            {
            //switches places
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            }
        }
    }
    if ((n%2)==0)   //if there are an even number of integers entered if statement will execute
    {
        int median= (a[n/2]+a[(n/2)-1])/2;    //averages middle two values
        return median;  //returns the average of two middle values
    }
    else
    {
        return a[(n/2)];    //if odd number of values entered middle value is returned
    }
}

//Find the mean of values entered
double findMean(int a[], int n)
{
    //initalize variables
    int i, meanTotal=0;
    double mean;

    for (i=0;i<n;++i) //loop to sum values entered
    {
       meanTotal= meanTotal+a[i]; //running total of entered integers
    }
    mean = meanTotal/n; //divides total by number of values entered
    return mean;    //returns mean
}

//Find variance
int findVar(int a[], int n, int mean)
{
    //initialize variables for calculation
    int i, var;
    long xSqTotal=0, xSq;

    for (i=0;i<n;++i)   //loop through all values entered
    {
       xSqTotal= xSqTotal+(a[i]*a[i]);  //squares current element and adds it to the total
    }
    xSq = xSqTotal/n;   //divides square total by number of data items
    var = xSq-(pow(mean,2.0));  //subtacts the square of the mean from the the xSq value
    return var;    //returns variance
}

//Find standard deviation
double findStdev(int var)
{
    //declares varible stdev and assigns the square root of the variance
    double stdev=sqrt(var);
    return stdev;   //returns standard deviation
}
