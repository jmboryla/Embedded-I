/*Class:Elec 1520
*Assignment:Pointers 3
*Program Author:Jonathan Boryla
*Date:October 16, 2017
*Tested on
*    C Environment:CodeBlocks
*    Operating System:Windows 10
*Description: This program initializes an array and uses a function to display an array using all pointer notation
*/
#include <stdio.h>

//function to display array using pointer notation
void displayArray(unsigned int *a, int asize, int fieldWidth, int showPerLine)
{
    //initializing a pointer to point at a, and a count variable
    unsigned int *ptra;
    int count;

    //prints titles
	puts("\n\nArray Values\n\n");

	//assigns a to ptra, initializes count to 0, for loop will run until prta is greater than or equal to the sum of a and asize, ptra and count are incremented
	for(ptra=a,count=0; ptra < (a+asize); ++ptra,++count)
	{
		if( (count % showPerLine) == 0) //prints new line whenever count is evenly divisible by showPerLine
			puts("");
		printf("%*d", fieldWidth, *ptra);   //prints whats in the address where ptra points as a decimal number

	}

	puts("\n");  // 2 blank lines
}


int main(void)
{

	const int alength = 20; //constant alength initialized to 20
	unsigned int arr[alength];  //unsigned int array of alength
    unsigned int *ptra; //unsigned int pointer ptra

	for(ptra = &arr[0]; ptra < (&arr[0]+alength); ++ptra)   //assigns the address of arr[0] to ptra, loop will run until ptra's address is greater or equal to the address of arr[0]+alength, ptra is incremented
		*ptra = ptra-(&arr[0]); //initializes the address ptra points at to the difference of ptra and the address of arr[0]

	displayArray(arr, alength, 8, 6);   //calls display array function and passes arr, 8, and 6 to the function

	return 0;
}
