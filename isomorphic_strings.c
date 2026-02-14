#include <stdbool.h>
#include <string.h>

/*
 Problem: Isomorphic Strings (LeetCode)

 Description:
 Two strings s and t are isomorphic if characters in s can be replaced
 to get t with a one-to-one mapping between characters.

 Approach:
 - If lengths differ, return false.
 - Use two fixed-size arrays (size 256 for ASCII).
 - One array maps characters from s → t.
 - Another array maps characters from t → s.
 - Ensure mapping is consistent in both directions (bijection).

 Time Complexity: O(n)
   Single pass through both strings.

 Space Complexity: O(1)
   Fixed-size arrays of 256 elements.
*/

bool isIsomorphic(char* s, char* t) {

    int lenS = strlen(s);
    int lenT = strlen(t);

    if (lenS != lenT) {
        return false;
    }

    int mapST[256] = {0};   // Mapping from s → t
    int mapTS[256] = {0};   // Mapping from t → s

    for (int i = 0; i < lenS; i++) {

        unsigned char cs = s[i];
        unsigned char ct = t[i];

        // If neither character has been mapped yet
        if (mapST[cs] == 0 && mapTS[ct] == 0) {
            mapST[cs] = ct + 1;   // +1 to avoid default 0 confusion
            mapTS[ct] = cs + 1;
        }
        else {
            // If mapping is inconsistent
            if (mapST[cs] != ct + 1 || mapTS[ct] != cs + 1) {
                return false;
            }
        }
    }

    return true;
}
