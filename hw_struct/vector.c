#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


vector getVectors(char** argv,int startIndex,int stopIndex, int dataSize)
{
    //initialize variables
    int i;
    int currentIndex;
    vector a;

    //loop ends when stop index or data size is reached
    for (i=0, currentIndex=startIndex; i<dataSize && currentIndex<=stopIndex;++i,++currentIndex)
    {
        switch(i)
        {
            case 0:
                a.x=atof(argv[currentIndex]); //saves first value to x coordinate of vector
                break;
            case 1:
                a.y=atof(argv[currentIndex]); // saves second value to y coordinate of vector
                break;
            case 2:
                a.z=atof(argv[currentIndex]); //saves third value to z coordinate of vector
                break;
        }
    }
    return a; //returns vector a
}

/********
* Name: vector add( a, b )
*
* Description: vector addition
*
* Inputs:
* Parameters:
* vector a 3D Cartesian coordinate vector
* vector b 3D Cartesian coordinate vector
* Globals:
* struct vector vector description in vector.h
*
* Process:
* [1] Declare vector to store result of a + b
* [2] Add x coordinates
* [3] Add y coordinates
* [4] Add z coordinates
* [5] return vector containing sum of a + b
*
* Return:
* type: vector
* value: a + b
*
*/

vector vectorAdd(vector a, vector b)
{
    vector sum;
    sum.x= a.x+b.x;
    sum.y=a.y+b.y;
    sum.z=a.z+b.z;
    return sum;
}

/********
* Name: vector subtract( a, b )
*
* Description: vector subtraction
*
* Inputs:
* Parameters:
* vector a 3D Cartesian coordinate vector
* vector b 3D Cartesian coordinate vector
* Globals:
* struct vector vector description in vector.h
*
* Process:
* [1] Declare vector to store result of a - b
* [2] Add x coordinates
* [3] Add y coordinates
* [4] Add z coordinates
* [5] return vector containing sum of a - b
*
* Return:
* type: vector
* value: a - b
*
*/
vector vectorSubtract(vector a,vector b)
{
    vector diff;
    diff.x=a.x-b.x;
    diff.y=a.y-b.y;
    diff.z=a.z-b.z;
    return diff;
}

/********
* Name: dot product a, b )
*
* Description: dot product
*
* Inputs:
* Parameters:
* vector a 3D Cartesian coordinate vector
* vector b 3D Cartesian coordinate vector
* Globals:
* struct vector vector description in vector.h
*
* Process:
* [1] Declare double type to store result of a * b
* [2] multiply x coordinates together
* [3] multiply y coordinates together
* [4] multiply z coordinates together
* [5] sum the products of the coordinates
* [6] return double containing product of a * b
*
* Return:
* type: double
* value: a * b
*
*/
double dotProduct(vector a, vector b)
{
    double dP=(a.x*b.x)+(a.y*b.y)+(a.z*b.z);
    return dP;
}

/********
* Name: magnitude ( a )
*
* Description: magnitude of vector
*
* Inputs:
* Parameters:
* vector a 3D Cartesian coordinate vector
* Globals:
* struct vector vector description in vector.h
*
* Process:
* [1] Declare double type to store result of magnitude
* [2] square the x coordinates
* [3] square the y coordinates
* [4] square the z coordinates
* [5] sum the squares of the coordinates
* [6] take the square root of the sums of all the squares
* [7] return double containing magnitude of vector
*
* Return:
* type: double
* value: magnitude a
*
*/
double findMagnitude(vector a)
{
    double magnitudeSq=(a.x*a.x)+(a.y*a.y)+(a.z*a.z);
    double magnitude=sqrt(magnitudeSq);
    return magnitude;
}

/********
* Name: find distance ( a , b )
*
* Description: distance between vector a and b
*
* Inputs:
* Parameters:
* vector a 3D Cartesian coordinate vector
* vector b 3D Cartesian coordinate vector
* Globals:
* struct vector vector description in vector.h
*
* Process:
* [1] Declare double type to store result of distance
* [2] square the difference between x coordinates
* [3] square the difference between y coordinates
* [4] square the difference between z coordinates
* [5] sum the squares of the coordinates
* [6] take the square root of the sums of all the squares
* [7] return double containing distance between the two vectors
*
* Return:
* type: double
* value: distance between a and b
*
*/
double findDistance(vector a, vector b)
{
    double distanceSq=((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y))+((a.z-b.z)*(a.z-b.z));
    double distance=sqrt(distanceSq);
    return distance;
}

/********
* Name: scale vector ( a )
*
* Description: vector a multiplied by a scalar
*
* Inputs:
* Parameters:
* vector a 3D Cartesian coordinate vector
* double scalar
* Globals:
* struct vector vector description in vector.h
*
* Process:
* [1] Declare vector type to store result of the scaled vector
* [2] multiply x coordinates by scalar
* [3] multiply y coordinates by scalar
* [4] multiply z coordinates by scalar
* [5] return vector containing scale of vector a
*
* Return:
* type: vector
* value: scalar * a
*
*/
vector scaleVector(vector a,double scalar)
{
    a.x=a.x*scalar;
    a.y=a.y*scalar;
    a.z=a.z*scalar;
    return a;
}

/********
* Name: angle between ( a , b )
*
* Description: angle between
*
* Inputs:
* Parameters:
* magnitude of vector a
* magnitude of vector b
* dot product of vectors a and b
*
* Globals:
* struct vector vector description in vector.h
*
* Process:
* [1] declare a double type variable to store the angle
* [2] take the arc cosine of the dot product divided by the product of the magnitude of the two vectors
* [3] multiply by 180/pi to convert to degrees
* [5] return double type variable containing scale angle between a and b
*
* Return:
* type: double
* value: angle between a and b
*
*/
double angleBetween(double magA, double magB, double dP)
{
    double angle= acos((dP)/(magA*magB));
    angle= angle*(180/3.1415926);
    return angle;
}

/********
* Name: cross product ( a , b )
*
* Description: cross product of vector a and b
*
* Inputs:
* Parameters:
* vector a 3D Cartesian coordinate vector
* vector b 3D Cartesian coordinate vector
* Globals:
* struct vector vector description in vector.h
*
* Process:
* [1] Declare vector type to store result of the cross product
* [2] take the determinant of the i vector and assign it to the x coordinate of the cross product
* [3] take the determinant of the j vector and assign it to the y coordinate of the cross product
* [4] take the determinant of the k vector and assign it to the z coordinate of the cross product
* [5] return vector containing cross product of the two vectors
*
* Return:
* type: vector
* value: a x b
*
*/
vector crossProduct(vector a, vector b)
{
    vector cross;
    cross.x=(a.y*b.z)-(a.z*b.y);
    cross.y=(a.z*b.x)-(a.x*b.z);
    cross.z=(a.x*b.y)-(a.y*b.x);
    return cross;
}

/********
* Name: normalize ( a )
*
* Description: normalize vector a to length 1
*
* Inputs:
* Parameters:
* vector a 3D Cartesian coordinate vector
* magnitude a
*
* Globals:
* struct vector vector description in vector.h
*
* Process:
* [1] Declare vector type to store the normalized vector
* [2] Divide the x coordinates of a by the magnitude of a
* [3] Divide the y coordinates of a by the magnitude of a
* [4] Divide the z coordinates of a by the magnitude of a
* [5] return vector containing the normalized vector
*
* Return:
* type: vector
* value: a / magnitude a
*
*/
vector normalizeVector(vector a,double magA)
{
    vector normalize;
    normalize.x= a.x/magA;
    normalize.y= a.y/magA;
    normalize.z= a.z/magA;
    return normalize;
}
