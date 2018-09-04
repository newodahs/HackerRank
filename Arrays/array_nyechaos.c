#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*
 * The basic problem statement here is to calculate the number of bribes
 * it would take for an array to end up in the presented final state.
 *
 * A bribe is basically a position swaping it's way to the left (where pos 0 of the
 * array is considered the 'head' of the queue).
 *
 * Each position can only bribe up to two people and any more than that is considered
 * 'Too chaotic' and should print as such.
 */

#define MAX_BRIBE 2
#define MAX(a,b)((a > b) ? a : b)

//Using a look-left solution; keeps it so we only have to look to the left by two
//positions rather than calculate across the entire array 
void minBribes(int iQueueLen, int* pQueue)
{
    int iBribeCnt = 0;

    if (!pQueue || iQueueLen <= 0)
        return;

    //let's try working backwards...
    for(int i = (iQueueLen - 1); i >= 0; i--)
    {
        //shortcut for obviously out-of-bounds bribes
        if ((pQueue[i] - (i + 1)) > MAX_BRIBE)
        {
            printf("Too chaotic\n");
            return;
        }

        //rip over the array, starting from labeled position and count bribes...
        //two to the left
        for(int j = MAX(0, pQueue[i] - 2); j < i; j++)
        {
            if (pQueue[j] > pQueue[i])
                ++iBribeCnt;
        }
    }

    printf("%d\n", iBribeCnt);
}

int main()
{
    int aiQ1[] = { 2, 1, 5, 6, 3, 4 };  //should be 5
    int aiQ2[] = { 6, 1, 2, 5, 4, 3 };  //should be Too chaotic

    //first parameter is number of positions in the array (total)
    //second parameter is the array
    minBribes(6, aiQ1);
    minBribes(6, aiQ2);

    return 0;
}
