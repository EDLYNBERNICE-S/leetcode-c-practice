#include <string.h>

/*
 Problem: Find the Index of the First Occurrence in a String (strStr)

 Approach:
 - Let h be the length of haystack and n be the length of needle.
 - For each possible starting index in haystack:
     - Compare characters of needle one by one.
     - If all characters match, return the current index.
 - If no match is found, return -1.

 Time Complexity: O(h * n)
 Space Complexity: O(1)
*/

int strStr(char* haystack, char* needle) {

    int h = strlen(haystack);
    int n = strlen(needle);

    // Edge case: empty needle
    if (n == 0) {
        return 0;
    }

    for (int i = 0; i <= h - n; i++) {

        int j = 0;

        while (j < n && haystack[i + j] == needle[j]) {
            j++;
        }

        // If we matched all characters of needle
        if (j == n) {
            return i;
        }
    }

    return -1;  // No match found
}
