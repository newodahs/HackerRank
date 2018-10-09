#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*
 * The idea here is to check s1 vs s2 see if they share a common substring.
 *
 * If they do have a common substring, print YES, otherwise print NO.
 *
 * A substring is defined as a single character in common between the two
 * strings.
 */

//This particular solution uses a simple array to mark off what we've already
//checked against.  This is super hacky but should work for ASCII characters
//upper and lowercase -- it could be refined a lot more than it is...
char* twoStrings(char* s1, char* s2) 
{
  //using basic memory trick to mark ones we've already gone over...
  //since I don't care to process the string(s) too much, just account for
  //the characters between upper and lowercase on the ASCII chart (though
  //they'll never actually be seen in our test data...)
  int aiChk[58] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                   0, 0, 0, 0};
 
  for (int i = 0; s1[i] != '\0'; i++) {
    int iAPos = s1[i] - 65;
    if (aiChk[iAPos] == 1) continue;
    else aiChk[iAPos] = 1;

      for (int j = 0; s2[j] != '\0'; j++) {
        if (s1[i] == s2[j])
          return "YES";
      }
    }
    return "NO";
}

int main()
{
    printf("%s\n%s\n", twoStrings("hello", "world"), twoStrings("blargh", "none"));

    return 0;
}
