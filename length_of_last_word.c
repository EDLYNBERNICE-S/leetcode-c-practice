#include <string.h>

/*
 Problem: Length of Last Word

 Approach:
 - Start scanning the string from the end.
 - Skip trailing spaces.
 - Count characters until the next space is found.
 - The count represents the length of the last word.

 Time Complexity: O(n)
 Space Complexity: O(1)
*/

int lengthOfLastWord(char* s) {

    int count = 0;
    int i = strlen(s) - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
}
