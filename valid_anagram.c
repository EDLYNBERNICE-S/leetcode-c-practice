/*
 Problem: Valid Anagram

 Description:
 Given two strings s and t, return true if t is an anagram of s,
 and false otherwise.

 Approach:
 - If lengths differ, they cannot be anagrams.
 - Use a frequency array of size 26 (for lowercase English letters).
 - Increment for characters in s and decrement for characters in t.
 - If all frequencies return to zero, the strings are anagrams.

 Time Complexity: O(n)
 Space Complexity: O(1)
*/

bool isAnagram(char* s, char* t) {

    if (strlen(s) != strlen(t)) {
        return false;
    }

    int freq[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            return false;
        }
    }

    return true;
}
