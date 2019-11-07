/*Class:Elec 1520
*Assignment:Files
*Program Author:Jonathan Boryla
*Date:October 27, 2017
*Tested on
*    C Environment:CodeBlocks
*    Operating System:Windows 10
*Description:This program reads in data from a sonar sensor, sorts through the data, calculates the x/y based position
based on angle and magnitude, then writes a filtered data file.
*/

#include <stdio.h> /*printf scanf*/
#include <stdlib.h> /*exit*/
#include <math.h> /*sin cos*/

//Macros
#define ROWS 37
#define COLS 6
#define ARRAY_SIZE ROWS*COLS
#define PI 3.141592

//Function Prototypes
void fillArray(int a[ROWS][COLS]);
void fillDegArray(int a[ROWS][COLS],int b[]);
void fillMedArray(int a[ROWS][COLS],int b[]);
void calcXYval(int mag[],int deg[],double x[],double y[]);
void writeFilteredFile(int deg[],int mag[],double x[],double y[]);


int main(void)
{
    //Declare arrays for storage of file values
    int readArray[ROWS][COLS];
    int degreeArray[ROWS];
    int medianArray[ROWS];
    double xDistance[ROWS];
    double yDistance[ROWS];


    fillArray(readArray); //call fill array function, passes readArray
    fillDegArray(readArray,degreeArray);    //call fillDegArray function, passes the read array that has been filled with file values and degreeArray
    fillMedArray(readArray,medianArray);    //call fillMedArray function, passes readArray and medianArray
    calcXYval(medianArray,degreeArray,xDistance,yDistance); //call calcXYval, passes medianArray, degreeArray, xDistance, and yDistance
    writeFilteredFile(degreeArray,medianArray,xDistance,yDistance); //call writeFilteredFile function, passes degreeArray, medianArray, xDistance,and yDistance



    return 0;
}

void fillArray(int a[ROWS][COLS]) //function to fill the array with values from file
{

    FILE *sonar; //declare file pointer called sonar
    int i,j;     //declare variables i, and j used in for loops
    sonar=fopen("sonarData.txt","r");   //open file 'sonarData.txt' to sonar file pointer
    if(sonar==NULL){    //check if file has opened
       fprintf(stderr,"File sonarData.txt could not open.\n");  //error message if file does not open
       exit(0);     //exits program
    }
    for (i=0;i<ROWS;++i)    //for loop i cycles through rows of array
        {
        for(j=0;j<COLS;++j) //for loop j cycles through columns of array
            {
            fscanf(sonar, "%d",&a[i][j]);   //scans file for decimal number and save it to a[i][j]
            fgetc(sonar);           //clears  ',' character from stream
            }
        }
    fclose(sonar);  //closes file
}

void fillDegArray(int a[ROWS][COLS],int b[]) //function to fill the degree array
{
    int i,j=0;  //declares variables to use in loop
    for(i=0;i<ROWS;++i,j++) //for loop cycles through rows
    {
        {
            b[j]=a[i][0];   //saves value at a[i][0] to b[j]

        }

    }
}

void fillMedArray(int a[ROWS][COLS],int b[]) //function to fill the median array
{
    int i, inner, outer;    //declare variables used in loops
    for(i=0;i<ROWS;++i) //loop through rows
    {
        for(outer=1;outer<COLS;++outer) //outer column loop for bubble sort initialized to first element to skip degree reading
        {
            for(inner=1;inner<COLS;++inner) //inner column loop for bubble sort
            {
                if(a[i][inner]>a[i][outer]) //if condition sorts sorts row from lowest to highest
                {
                    //switch places
                    int dummy=a[i][inner];
                    a[i][inner]=a[i][outer];
                    a[i][outer]=dummy;
                }
            }
        }
        b[i]=a[i][3]; //saves the value of a[i][3] the median value to b[j]
    }
}

void calcXYval(int mag[],int deg[],double x[],double y[]) //function to calculate x and y value based on angle and magnitude
{
    int i;  //initialize variables used in loop
    for(i=0;i<ROWS;++i) //loops through rows
    {
        x[i]=mag[i]*cos(deg[i]*PI/180); //calculates x position using cosine function
        y[i]=mag[i]*sin(deg[i]*PI/180); //calculates y position using sine function
    }
}

void writeFilteredFile(int deg[],int mag[],double x[],double y[]) //function to write the filtered data to a file
{
    FILE *filtered; //declare file pointer named filtered
    filtered=fopen("filteredData.txt","w"); //opens file filteredData for writing
    if(filtered==NULL){ //check if file at file pointer filtered is open
        fprintf(stderr,"Could not open file filteredData.txt.\n");  //error message if file fails to open
        exit(0);       //exits program
    }

    int i;  //declares i used in for loop
    fprintf(filtered,"%-12s%-12s%10s%10s\n","Angle","Radial","","");    //prints titles for columns in file
    fprintf(filtered,"%-12s%-12s%10s%10s\n","(Degrees)","Distance(cm)","X","Y");
    for (i=0;i<ROWS;++i)    //loop cycles through all arrays
    {
        fprintf(filtered,"%-12d%-12d%10.2f%10.2f\n",deg[i],mag[i],x[i],y[i]);   //prints the [i] value of every array in appropriate column
    }
    fclose(filtered); //close file
}
