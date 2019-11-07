/*=============================================================================
 |   Assignment:  Homework 12 - Structures
 |
 |       Author:  Jonathan Boryla
 |
 |        Class:  Embedded Systems Engineering - ELEC 1520

 |   Instructor:  Prof. Diane Williams

 |     Due Date:  November 6, 2017
 |
 +-----------------------------------------------------------------------------
 |
 |  Description: This program takes in the coordinates of two vectors and test different functions on the two vectors
 |
 |        Input:  Two vectors with three coordinates each, and a signed scalar must be input
 |
 |       Output:  If the correct number of arguments is not entered the program exits. Otherwise, the program
 |                performs several calculations based on the two vectors entered as well as the entered scalar.
 |
 |    Algorithm: Vector values are acquired separately from command arguments, then passed to each function for the
 |                necessary calculations.
 |
 |   Required Features Not Included:  All required features are included in this program
 |
 |   Known Bugs:  If the program does not receive valid input data, then the program output will not be valid.
 |
 *===========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "vector.h"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
    #define M_PI_2 1.57079632679489661923
#endif

int main (int argc,char** argv)
{
    //initialize variables
    vector a = {.x=0.0,.y=0.0,.z=0.0};
    vector b = {.x=0.0,.y=0.0,.z=0.0};
    vector sum, diff, crossP, scalar, normalize;
    double magnitudeA,magnitudeB, distance, dotP, angle;
    double scaleBy=atof(argv[7]);

   // argument count must be at least 8
   // Display error message and terminate program execution
   // if there are not at least eight arguments
    if (argc<7)
    {
        fprintf(stderr,"Not enough information. Enter 6 vector coordinates and one scalar. Format a.x a.y a.z b.x b.y b.z scalar");
        exit(1);
    }

    // argv[0] is name of executable
    // next 3 arguments are x, y, and z coordinates of vector a
    // convert string arguments to double, store in vector a
    a=getVectors(argv,1,3,3);

    // next 3 arguments are x, y, and z coordinates of vector b
    // convert string arguments to double, store in vector b
    b=getVectors(argv,4,6,3);

     // Print vector a and vector b data
    fprintf(stdout,"Command Line Vector Input\n\n");
    fprintf(stdout,"%5s%10.2f,%5s%10.2f,%5s%10.2f\n","a.x:",a.x,"a.y:",a.y,"a.z",a.z);
    fprintf(stdout,"%5s%10.2f,%5s%10.2f,%5s%10.2f\n","b.x:",b.x,"b.y:",b.y,"b.z",b.z);

    // Test each of the vector library functions and display the
    // results
    fprintf(stdout,"\n\n\n*** Testing Vector Library Functions ***\n\n\n");

    // test magnitude
    magnitudeA=findMagnitude(a);
    magnitudeB=findMagnitude(b);
    fprintf(stdout,"%-20s%10.2f\n","magnitude<a>:",magnitudeA);
    fprintf(stdout,"%-20s%10.2f\n","magnitude<b>:",magnitudeB);

    // test distance
    distance=findDistance(a,b);
    fprintf(stdout,"\n%-20s%10.2f\n","Distance<a,b>:",distance);

    // test dot product
    dotP=dotProduct(a,b);
    fprintf(stdout,"%-20s%10.2f\n","Dot Product<a,b>:",dotP);

    //test angle between, display angle in degrees
    angle=angleBetween(findMagnitude(a),findMagnitude(b),dotProduct(a,b));
    fprintf(stdout,"\n%-20s%10.2f degrees\n\n","AngleBetween<a,b>:",angle);

    fprintf(stdout,"\n%30s%9s%9s%9s\n","","c.x","c.y","c.z");

    // test vector addition
    sum=vectorAdd(a,b);
    fprintf(stdout,"\n%-30s%9.2f%9.2f%9.2f\n","c = add<a,b>",sum.x,sum.y,sum.z);

    // test vector subtraction
    diff=vectorSubtract(a,b);
    fprintf(stdout,"\n%-30s%9.2f%9.2f%9.2f\n","c = subtract<a,b>",diff.x,diff.y,diff.z);

    // test cross product
    crossP=crossProduct(a,b);
    fprintf(stdout,"\n%-30s%9.2f%9.2f%9.2f\n","c = crossProduct<a,b>",crossP.x,crossP.y,crossP.z);

    //test multiply scalar
    scalar=scaleVector(a,scaleBy);
    fprintf(stdout,"\n%-22s%-5.2f%-3s%9.2f%9.2f%9.2f\n","c = multiplyScalar<a,",scaleBy,">",scalar.x,scalar.y,scalar.z);

    //test normalize vector
    normalize=normalizeVector(a,findMagnitude(a));
    fprintf(stdout,"\n%-30s%9.2f%9.2f%9.2f\n\n\n","c = normalize<a>",normalize.x,normalize.y,normalize.z);



    return 0;
}
