#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/*
 * Similar to the 'two strings' problem, except we're looking at whole words from a
 * randsom note compared to a source (magazine); if the randsom note cannot match
 * the source print No, otherwise print Yes.
 *
 * Words from the magazine can only be used once, so if there are duplicates in the
 * randsom note, then they must be duplicated in the magazine.
 */

// Complete the checkMagazine function below.
void checkMagazine(int magazine_count, char** magazine, int note_count, char** note)
{
    int iCnt = 0;
    if (note_count > magazine_count) { printf("No\n"); return; }

    //work through the note as it's at least equal to or less than
    //the magazine, and if we can't find the word in the magazine
    //it's dead to us...
    for(int i = 0; i < note_count; i++)
    {
        int iChk = 0;
        for(int j = 0; j < magazine_count; j++)
        {
            if (magazine[j] && !strcmp(note[i], magazine[j]))
            {
               //bump our count
               ++iCnt;
               iChk = 1;
               if (iCnt == note_count) { printf("Yes\n"); return; }

               //'cut' out the magazine entry
               magazine[j] = NULL;
               break;
            }
        }
        if (!iChk) break;
    }

    printf("No\n");
}

int main()
{
   char* pacTest1Mag[5] = {"aaef", "afejki", "jklhie", "navrnie", "ineifa"};
   char* pacTest1Randsom[4] = {"afejki", "jklhie", "navrnie", "ineifa"};
   checkMagazine(5, pacTest1Mag, 4, pacTest1Randsom);

   char* pacTest2Mag[5] = {"aaef", "afejki", "jklhie", "navrnie", "ineifa"};
   char* pacTest2Randsom[5] = {"afejki", "jklhie", "navrnie", "ineifa", "babwaj"};
   checkMagazine(5, pacTest2Mag, 5, pacTest2Randsom);

   return 0;
}
