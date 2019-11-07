/*=========================================================
| Author: Jonathan Boryla
| Class: ELEC 1520, Embedded Systems Engineering I
| Instructor: Prof. Diane Williams
| Due Date:November 6, 2017
|
| Filename: vector.h
|
| Description:
|     File contains vector library function prototypes
|     and vector structure definition.
|
|  Global: struct vector
|
|  Functions:
|     getVectors
|     findMagnitude
|     vectorAdd
|     vectorSubtract
|     scaleVector
|     findDistance
|     dotProduct
|     crossProduct
|     normalizeVector
|     angleBetween
|
==========================================================*/

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED


/*============ Global Data Structures ====================*/

/** 3D Cartesian coordinate vector data structure */

typedef struct{double x; double y; double z;}vector;



/*============ FUNCTION PROTOTYPES ======================*/
/********
*  Name:    getVectors
*
*  Description: retrieves vector values from command arguments
*
*  Inputs:
*     Parameters:
*      char** argv       argument stream from command prompt
*      int startIndex    start of vector input
*      int stopIndex     end of vector input
*      int dataSize      size of vector input
*     Globals:
*        struct vector  vector description in vector.h
*
*  Return:
*        type: vector
*        value: a
*
*/
vector getVectors(char** argv,int startIndex,int stopIndex,int dataSize);

/********
*  Name:    vector add( a, b )
*
*  Description: vector addition
*
*  Inputs:
*     Parameters:
*        vector a       3D Cartesian coordinate vector
*        vector b       3D Cartesian coordinate vector
*     Globals:
*        struct vector  vector description in vector.h
*
*  Return:
*        type: vector
*        value: a + b
*
*/
vector vectorAdd(vector a, vector b);

/********
*  Name:    vectorSubtract( a, b )
*
*  Description: vector subtraction
*
*  Inputs:
*     Parameters:
*        vector a       3D Cartesian coordinate vector
*        vector b       3D Cartesian coordinate vector
*     Globals:
*        struct vector  vector description in vector.h
*
*  Return:
*        type: vector
*        value: a - b
*
*/
vector vectorSubtract(vector a,vector b);

/********
*  Name:    dotProduct( a, b )
*
*  Description: dot product of two vectors
*
*  Inputs:
*     Parameters:
*        vector a       3D Cartesian coordinate vector
*        vector b       3D Cartesian coordinate vector
*     Globals:
*        struct vector  vector description in vector.h
*
*  Return:
*        type: double
*        value: a*b
*
*/
double dotProduct(vector a, vector b);

/********
*  Name:    crossProduct( a, b )
*
*  Description: cross product of two vectors
*
*  Inputs:
*     Parameters:
*        vector a       3D Cartesian coordinate vector
*        vector b       3D Cartesian coordinate vector
*     Globals:
*        struct vector  vector description in vector.h
*
*  Return:
*        type: vector
*        value: a x b
*
*/
vector crossProduct(vector a, vector b);

/********
*  Name:    findMagnitude( a )
*
*  Description: finds the length of vector
*
*  Inputs:
*     Parameters:
*        vector a       3D Cartesian coordinate vector
*     Globals:
*        struct vector  vector description in vector.h
*
*  Return:
*        type: double
*        value: magnitude(a)= sqrt((a.x*a.x)+(a.y*a.y)+(a.z*a.z))
*
*/
double findMagnitude(vector a);

/********
*  Name:    findDistance( a, b )
*
*  Description: find the distance from the tip of one vector to the other
*
*  Inputs:
*     Parameters:
*        vector a       3D Cartesian coordinate vector
*        vector b       3D Cartesian coordinate vector
*     Globals:
*        struct vector  vector description in vector.h
*
*  Return:
*        type: double
*        value: distance=sqrt((a.x-b.x)^2 + (a.y-b.y)^2 + (a.z-b.z)^2)
*
*/
double findDistance(vector a, vector b);

/********
*  Name:    scaleVector( a, scalar )
*
*  Description: scales the components of vector a
*
*  Inputs:
*     Parameters:
*        vector a       3D Cartesian coordinate vector
*        scalar         a double type scalar
*     Globals:
*        struct vector  vector description in vector.h
*
*  Return:
*        type: vector
*        value: scaleA= <a.x*scalar , a.y*scalar , a.z*scalar>
*
*/
vector scaleVector(vector a,double scalar);

/********
*  Name:    dotProduct( a, b )
*
*  Description: dot product of two vectors
*
*  Inputs:
*     Parameters:
*        vector a       3D Cartesian coordinate vector
*        vector b       3D Cartesian coordinate vector
*     Globals:
*        struct vector  vector description in vector.h
*
*  Return:
*        type: double
*        value: a*b
*
*/
double angleBetween(double magA, double magB, double dP);

/********
*  Name:    normalizeVector(a)
*
*  Description: normalizes length of vector to unit vector
*
*  Inputs:
*     Parameters:
*        vector a       3D Cartesian coordinate vector
*        magnitude a    length of vector a
*     Globals:
*        struct vector  vector description in vector.h
*
*  Return:
*        type: vector
*        value: normalize a= <a.x/magnitude a , a.y/magnitude a , a.z/magnitude a>
*
*/
vector normalizeVector(vector a,double magA);


#endif // VECTOR_H_INCLUDED

