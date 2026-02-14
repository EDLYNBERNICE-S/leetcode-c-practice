#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/*
 Problem: Word Pattern (LeetCode)

 Description:
 Check if a string follows the same pattern.
 Each character in the pattern must map to exactly one word,
 and no two characters can map to the same word.

 Approach:
 - Split the string using strtok.
 - Maintain a mapping from pattern characters to words.
 - Ensure bijection (one-to-one mapping).
 - If mismatch occurs, return false.

 Time Complexity: O(n)
   Each word and pattern character is processed once.

 Space Complexity: O(n)
   For storing tokenized words and mappings.
*/

bool wordPattern(char *pattern, char *s) {

    if (pattern == NULL || s == NULL) {
        return false;
    }

    // Duplicate string since strtok modifies input
    char *copy = strdup(s);
    if (copy == NULL) {
        return false;
    }

    int patternLen = strlen(pattern);

    // Allocate memory for storing words
    char *words[patternLen];
    int wordCount = 0;

    char *token = strtok(copy, " ");
    while (token != NULL && wordCount < patternLen) {
        words[wordCount++] = token;
        token = strtok(NULL, " ");
    }

    // If word count does not match pattern length → invalid
    if (wordCount != patternLen || token != NULL) {
        free(copy);
        return false;
    }

    // Mapping from character to word
    char *charToWord[26] = {NULL};

    for (int i = 0; i < patternLen; i++) {
        int index = pattern[i] - 'a';

        if (charToWord[index] == NULL) {

            // Ensure word is not already mapped to another character
            for (int j = 0; j < 26; j++) {
                if (charToWord[j] != NULL &&
                    strcmp(charToWord[j], words[i]) == 0) {
                    free(copy);
                    return false;
                }
            }

            charToWord[index] = words[i];

        } else {
            // If mapping exists but does not match → invalid
            if (strcmp(charToWord[index], words[i]) != 0) {
                free(copy);
                return false;
            }
        }
    }

    free(copy);
    return true;
}
