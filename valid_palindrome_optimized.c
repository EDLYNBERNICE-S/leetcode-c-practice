
/*
 Problem: Valid Palindrome

 Description:
 This function checks whether a given string is a palindrome.
 It ignores non-alphanumeric characters and compares letters in a case-insensitive manner.

 Approach:
 - Use two pointers starting from the beginning and end of the string.
 - Move pointers inward while skipping non-alphanumeric characters.
 - Compare characters after converting them to lowercase.

 Time Complexity: O(n)
   - Each character in the string is processed at most once.

 Space Complexity: O(1)
   - Only constant extra space is used.

*/

int isPalindrome(char *text) {
    int left = 0;
    int right = strlen(text) - 1;

    while (left < right) {

        // Skip non-alphanumeric characters from the left
        while (left < right && !isalnum(text[left])) {
            left++;
        }

        // Skip non-alphanumeric characters from the right
        while (left < right && !isalnum(text[right])) {
            right--;
        }

        // Compare characters (case-insensitive)
        if (tolower(text[left]) != tolower(text[right])) {
            return 0;   // Not a palindrome
        }

        left++;
        right--;
    }

    return 1;   // It is a palindrome
}
