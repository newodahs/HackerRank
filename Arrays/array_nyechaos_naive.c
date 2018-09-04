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

//Naive approach to the minimum bribe problem from NYE chaos
void minBribes(int iQueueLen, int* pQueue)
{
    int iBribeCnt = 0;

    if (!pQueue || iQueueLen <= 0)
        return;

    //going left to right in the queue to calculate
    for(int i = 0; i < iQueueLen; i++)
    {
        //minus 1 to account for zero-based offsets
        int iPDif = (pQueue[i] - 1) - i;
        //check simple diffs first
        if (iPDif < 0) iPDif = 0;

        //catch any already bribed stragglers that also moved, especially near the end
        if (!iPDif)
        {
            for (int j = (i + 1); j < (iQueueLen); j++)
            {
                if (pQueue[i] > pQueue[j])
                    ++iPDif;
            }
        }

        //if we've gone over MAX_BRIBE in this run, we're done here...
        if (iPDif > MAX_BRIBE)
        {
            printf("Too chaotic\n");
            return;
        }

        iBribeCnt += iPDif;
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
