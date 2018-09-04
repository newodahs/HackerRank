#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*
 * Example of using a Fenwick Tree to update a range of values across
 * an array (init'd to zero) and then return the largest value
 */

//algorithm assumes 3 rows where:
//col a -> start of array mod
//col b -> end of array mod
//col c -> amount to mod-by from a -> b

#define ARRAY_SIZE 40
#define QUERY_ROWS 20
#define EXPECTED_RESULT 4762L
int _aiQueries[QUERY_ROWS][3] = 
{ 
   { 24, 40, 783 },
   { 8, 26, 229 }, 
   { 20, 31, 114 }, 
   { 10, 22, 319 },
   { 16, 23, 152 }, 
   { 12, 24, 53 },
   { 11, 22, 331 },
   { 4, 22, 304 },
   { 5, 30, 1029 },
   { 2, 25, 23 },
   { 17, 24, 547 },
   { 5, 10, 95 },
   { 17, 22, 135 },
   { 24, 35, 254 },
   { 11, 20, 550 },
   { 30, 34, 31 },
   { 31, 38, 54 },
   { 17, 31, 964 },
   { 8, 32, 12 },
   { 26, 35, 227 },
};

//helper macros for finding max values of two values and to calculate least significant bit given a value
#define MAX(a,b) ((a > b) ? a : b)
#define LSB(a) ((a) &- (a))

void arrayAdd(int iPos, long lVal, long* pArr, size_t szArrLen)
{
    if (!pArr) return;
    
    //update the binary indexed array
    for(; iPos <= (int)szArrLen; iPos += LSB(iPos))
    {
        pArr[iPos] += lVal;
    }
}

long arrayVal(int iPos, long* pArr)
{
    long lRet = 0;
    if (!pArr) return 0;
    
    //pull the value from the binary indexed array
    for(; iPos > 0; iPos -= LSB(iPos))
    {
        lRet += pArr[iPos];
    }
    return lRet;
}

// Complete the arrayManipulation function below.
long manipulateArray(int n, int iQRows, int aiQueries[][3]) 
{
    long lRet = 0;

    //some basic error checking
    if (n <= 0 || !aiQueries) return 0;
    
    long* pArr = (long*)calloc((n + 1), sizeof(long));
    if (!pArr) return 0;
    
    //rip over the query and make the updates
    for(int i = 0; i < iQRows; i++)
    {
        //if we use arrayAdd to update as a range
        arrayAdd(aiQueries[i][0], aiQueries[i][2], pArr, n);   //start at pos a
        arrayAdd(aiQueries[i][1] + 1, -(aiQueries[i][2]), pArr, n);   //end at pos b
    }
    
    //pull back the max value... arrayVal should give us back just the position
    //and check it agianst the last maximum
    for(int j = 1; j <= n; j++)
    {
        lRet = MAX(lRet, (arrayVal(j, pArr)));
    }

    free(pArr); pArr = NULL;
    
    return lRet;
}

int main()
{

    long lRes = manipulateArray(ARRAY_SIZE, QUERY_ROWS, _aiQueries);

    printf("Computed Result: %ld\n", lRes);
    printf("Expected Result: %ld\n", EXPECTED_RESULT);

    if (lRes == EXPECTED_RESULT)
       printf("Success!\n");
    else
       printf("Failure!\n");

    return 0;
}

