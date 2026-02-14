/*
 Problem: Longest Common Prefix

 Approach:
 - Take the first string as the initial prefix.
 - Compare this prefix with each next string.
 - If mismatch occurs, reduce the prefix length by 1 from the end.
 - Repeat until it matches or becomes empty.

 Time Complexity: O(n * m)
 Space Complexity: O(1)
*/

char* longestCommonPrefix(char** strs, int strsSize) {

    if (strsSize == 0) {
        return "";
    }

    char *prefix = strs[0];

    for (int i = 1; i < strsSize; i++) {

        // Keep reducing prefix until it matches current string
        while (strncmp(prefix, strs[i], strlen(prefix)) != 0) {

            // Reduce prefix length by removing last character
            prefix[strlen(prefix) - 1] = '\0';

            // If prefix becomes empty, no common prefix exists
            if (strlen(prefix) == 0) {
                return "";
            }
        }
    }

    return prefix;
}
