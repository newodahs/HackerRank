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

//Naive solution, just compares character by character
char* twoStrings(char* s1, char* s2) 
{
  for (int i = 0; s1[i] != '\0'; i++) {
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
