/*Class:Elec 1520
*Assignment:Pointers 4
*Program Author:Jonathan Boryla
*Date:October 16, 2017
*Tested on
*    C Environment:CodeBlocks
*    Operating System:Windows 10
*Description: This program fills an array with random generated values and then prints and original unsorted array, then sorts the array in ascending value and prints the sorted array.
All functions utilize pointer notation
*/
#include <stdio.h>
#include <stdlib.h>

//fill array with random values
void fillArray(int *a, int asize, int lowValue, int highValue)
{
    int i;
	for(i = 0; i < asize; ++i)
		*(a+i) = rand()%(highValue-lowValue+1) + lowValue;  //the address of a+i is assigned a random value in the range of lowValue to highValue
}

//display array function
void displayArray(int *a, int asize, int fieldWidth, int numPerLine)
{
    //initialize i and a pointer to point at a
    int i;
    int *ptra;

    //assign a to ptra, and initialize i to zero, loop will continue until i is greater than or equal to asize, ptra and i are incremented
	for(ptra=a, i = 0; i < asize;++ptra, ++i)
	{
		if( (i % numPerLine) == 0)  //if i is evenly divisible by numPerLine a new line is printed
			puts("");
		printf("%*d", fieldWidth, *ptra);   //the value in the ptra points at is printed
	}
	puts("");			// blank line
}

/* Sort array elements into ascending order */
void bubbleSort(int *a, int asize)
{
    //initialize varaibles for calculations, and a pointer that points at a
    int inner, outer;
    int *ptra=a;

    //outer for loop
	for(outer = 0; outer < asize; ++outer)
	{
	    //inner for loop
	    for(inner = 0; inner < asize; ++inner)
		{
			if(*(ptra+outer) < *(ptra+inner)) //the value in (ptra+outer) is compared to the value in (ptra+inner) if the value is less the following code executes
			{
				int temp = *(ptra+outer);   //dummy variable to store value of (ptra+outer)
				*(ptra+outer) = *(ptra+inner);  //(ptra+outer) is assigned the value of (ptra+inner)
				*(ptra+inner) = temp;   //the value of (ptra+outer) is assigned to (ptra+inner) via the dummy variable
			}
		}
	}
}

//main function
int main(void)
{
    //initializing constants
	const int arraySize = 30;
	const int fieldWidth = 5;
	const int printPerLine = 6;
	const int lowRandom = -100;
	const int highRandom = 100;

	//declaring an array arr of arraySize
	int arr[arraySize];


	//seeding the random generator function
	srand(0);

	//calling fillArray function, and passing the array, size of the array, highest and lowest random values
	fillArray(arr, arraySize, lowRandom, highRandom);

	//title for unsorted array
	puts("\nUnsorted Array\n");

	//calls displayArray function passing the array, the array size, the field width, and the amount to print per line
	displayArray(arr, arraySize, fieldWidth, printPerLine);

    //calls the bubbleSort function passing the array and size
	bubbleSort(arr, arraySize);

    //title for sorted array
	puts("\nSorted Array\n");

	//calls displayArray function passing the same parameters
	displayArray(arr, arraySize, fieldWidth, printPerLine);

	return 0;
}
