/*
 Problem: Palindrome Number

 Description:
 Given an integer x, return true if x is a palindrome,
 and false otherwise.

 A palindrome reads the same forward and backward.

 Constraints:
 - Do not convert integer to string.
 - Must handle overflow properly.

 Approach:
 - Negative numbers are not palindromes.
 - Numbers ending in 0 (except 0 itself) are not palindromes.
 - Reverse only half of the number.
 - Compare first half with reversed second half.

 Time Complexity: O(log10(n))
 Space Complexity: O(1)
*/

bool isPalindrome(int x) {

    // Negative numbers and numbers ending with zero
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int reversedHalf = 0;

    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // For even length: x == reversedHalf
    // For odd length: ignore middle digit → reversedHalf / 10
    return (x == reversedHalf || x == reversedHalf / 10);
}
