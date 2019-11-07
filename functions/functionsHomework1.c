#include <stdio.h>
#include <stdlib.h>


//Macros
#define ARRAY_SIZE 50
#define QUIT_PROGRAM 7

//Function Prototypes
void displayMainMenu (void);
void clearStandardIn (void);
int getUserChoice (void);
void fillArray (int a[], int aSize,int hVal,int lVal);
int getLow (void);
int getHigh (void);
int sumArray(int a[],int aSize);
int averageArray(int sum,int aSize);
int highestValue(int a[],int aSize,int low);
int lowestValue(int a[],int aSize,int high);
void displayArray(int a[],int aSize);

//Function Definitions
int main(void)
{
    printf("\nELEC 1520, Functions Homework, Jonathan Boryla\n\n");

    int userSelection=0;
    int high, low;
    int arraySum, arrayAvg, arrayHigh, arrayLow;
    int randomArray[ARRAY_SIZE] = {0};


    while (userSelection != QUIT_PROGRAM)
    {
        userSelection = getUserChoice();
        arraySum=sumArray(randomArray,ARRAY_SIZE);
        arrayAvg=averageArray(arraySum,ARRAY_SIZE);

        switch(userSelection)
        {
            case 1:
                low = getLow();
                high = getHigh();
                while(high<low)
                {
                    puts("\n\nHigh value must be greater than low value. Please try again.\n");
                    low = getLow();
                    high = getHigh();
                }
                fillArray(randomArray,ARRAY_SIZE,high,low);
                break;
            case 2:
                printf("\n\nThe sum of the random values is: %d\n\n",arraySum);
                break;
            case 3:
                printf("\n\nThe average of the random values is: %d\n\n",arrayAvg);
                break;
            case 4:
                arrayHigh=highestValue(randomArray,ARRAY_SIZE,low);
                printf("\n\nThe highest random value is: %d\n\n",arrayHigh);
                break;
            case 5:
                arrayLow=lowestValue(randomArray,ARRAY_SIZE,high);
                printf("\n\nThe lowest random value is: %d\n\n",arrayLow);
                break;
            case 6:
                displayArray(randomArray,ARRAY_SIZE);
                break;
        }

    }
   return 0;
}

void displayMainMenu (void)
{
   printf("Main Menu\n\n"
        "Enter a number to choose one of the following actions:\n"
        "\t1.  Fill the array with random values\n"
        "\t2.  Sum the array\n"
        "\t3.  Average value of the array\n"
        "\t4.  Find the maximum value in array\n"
        "\t5.  Find the minimum value in array\n"
        "\t6.  Display the array values\n"
        "\t7.  Quit the program\n"
        "  Enter your selection: ");
}

void clearStandardIn (void)
{
    while ((char)getchar()!='\n');
}

int getUserChoice (void)
{
    int choice=0;
    int returnVal;
    displayMainMenu();
    returnVal=scanf("%d",&choice);
    while(returnVal!=1)
    {
        clearStandardIn();
        displayMainMenu();
        returnVal=scanf("%d",&choice);
    }
    clearStandardIn();
    return choice;
}

void fillArray (int a[], int aSize,int hVal,int lVal)
{
    int i;
    for(i=0;i<aSize;++i)
    {
        a[i]=(rand()%(hVal-lVal+1))+lVal;
    }

}
int getLow (void)
{
    int userLow, returnVal;
    printf("\nWhat range of random values?\n\n"
           "Enter lowest random value: ");
    returnVal=scanf("%d",&userLow);
     while(returnVal!=1)
    {
        clearStandardIn();
        printf("\nWhat range of random values?\n\n"
           "Enter lowest random value: ");
        returnVal=scanf("%d",&userLow);
    }
    clearStandardIn();
    return userLow;
}
int getHigh (void)
{
    int userHigh, returnVal;
    printf("\nEnter highest random value: ");
    returnVal= scanf("%d",&userHigh);
    while(returnVal!=1)
    {
        clearStandardIn();
        printf("\nEnter highest random value: ");
        returnVal= scanf("%d",&userHigh);
    }
    clearStandardIn();
    return userHigh;
}

int sumArray(int a[],int aSize)
{
    int sum=0,i;
    for (i=0;i<aSize;i++)
    {
        sum=a[i]+sum;
    }
    return sum;
}

int averageArray(int sum,int aSize)
{
    int average;
    average=sum/aSize;
    return average;
}

int highestValue(int a[],int aSize,int low)
{
    int highVal=low,i;
    for (i=0;i<aSize;i++)
    {
        if (a[i]>highVal)
            highVal=a[i];
    }
    return highVal;
}

int lowestValue(int a[],int aSize,int high)
{
    int lowVal=high,i;
    for (i=0;i<aSize;i++)
    {
        if (a[i]<lowVal)
            lowVal=a[i];
    }
    return lowVal;
}

void displayArray(int a[],int aSize)
{
    int i;
    for (i=0;i<aSize;++i)
    {
        if(i%10==0)
        printf("\n\n");
        printf("%5d",a[i]);

    }
    printf("\n\n");
}
