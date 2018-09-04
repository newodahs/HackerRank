#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*
 * Example of the naive approach to updating a range of values across
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

long manipulateArray(int n, int iQRows, int aiQueries[][3]) 
{
    long lRet = 0;
    if (n <= 0) return 0;

    //not paying attention, I had assumed int here...it should be a long...
    long* pArr = (long*)calloc(n, sizeof(long));
    if (!pArr) return 0;

    //manipulate the array - we should be able to use int here as long
    //as we don't go over int max for the rows (and columns below)
    for(int i = 0; i < iQRows; i++)
    {
        for(int iCol = (aiQueries[i][0] - 1); iCol < (aiQueries[i][1]); iCol++)
        {
            pArr[iCol] += aiQueries[i][2];
            lRet = MAX(lRet, pArr[iCol]);
        }
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

