#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*
 * When given an unordered array of consecutive integers and no duplicates
 * minSwaps will calculate the number of swaps needed to order said array.
 *
 * This function also happens to swap the array in memory for you, though
 * it's not required (only the count of swaps is needed...)
 */

int minSwaps(int arr_count, int* arr)
{
    int iCnt = 0;
    if (arr_count <= 0 || !arr) return 0;

    //rip over our array from start to end
    for(int i = 0; i < arr_count; i++)
    {
        //we're already swapped to the right location; plus one for zero based arrays
        if (arr[i] == (i + 1))
            continue;

        //HACK: the problem description says 'consecutive', however some test cases aren't..
        if (arr[i] > arr_count)
            continue;

        //rip over the array starting from our current position and find our swap partner for
        //this position
        int j = i;
        while(arr[j] != (i + 1))
        {
            ++j;
        }

        //do the swap inline
        int iTmp = arr[i];
        arr[i] = arr[j];
        arr[j] = iTmp;

        iCnt++;
    }

    return iCnt;
}

int main()
{
   int aiArray[] = { 10, 4, 3, 6, 7, 9, 8, 1, 2, 5 };
   int iRet = minSwaps(10, aiArray);  //should require 7 swaps

   printf("Swaps needed: %d\n", iRet);

   return 0;
}
