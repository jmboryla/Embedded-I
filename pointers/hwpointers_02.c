/*Class:Elec 1520
*Assignment:Pointers 2
*Program Author:Jonathan Boryla
*Date:October 16, 2017
*Tested on
*    C Environment:CodeBlocks
*    Operating System:Windows 10
*Description: This program prints the address and stored data of a variable and a pointer to that variable
*/

#include <stdio.h>

int main(void)
{
    //declares dval as double initialized to 3.14 and double pointer pdval is given the address of dval
	double dval = 3.14;
	double *pdval = &dval;

	printf("%-12s%-12s%-12s\n","Name","Address","Stored Data"); //Titles for the printout
	printf("%-12s%2s%-10p%-12lf\n","dval","0x",(void*)&dval,dval);     //prints the address of dval and value stored in dval
    printf("%-12s%2s%-10p%2s%-10p\n","pdval","0x",(void*)&pdval,"0x",(void*) pdval);  //prints the address of pdval and the value stored in pdval
    printf("%-12s%2s%-10p%-12lf\n","*pdval","0x",(void*)&*pdval,*pdval);   //prints address of *pdval and the value stored in *pdval

	return 0;
}

