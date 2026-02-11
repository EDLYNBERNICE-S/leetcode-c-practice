#include <stdlib.h>

/*
 Problem: Plus One (LeetCode)

 Description:
 Given an array of digits representing a non-negative integer,
 increment the number by one and return the resulting array.

 Approach:
 - Start adding 1 from the last digit.
 - Handle carry if digit becomes 10.
 - If carry remains after the most significant digit,
   create a new array with one extra digit.

 Time Complexity: O(n)
 Space Complexity: O(n)
*/

int* plusOne(int* digits, int digitsSize, int* returnSize) {

    int carry = 1;   // We are adding 1 initially
    int index = digitsSize - 1;

    // Process digits from right to left
    while (index >= 0 && carry) {
        int sum = digits[index] + carry;
        digits[index] = sum % 10;
        carry = sum / 10;
        index--;
    }

    // If no carry remains, we can return the modified input array
    if (carry == 0) {
        *returnSize = digitsSize;
        return digits;
    }

    // If carry remains, allocate new array with one extra digit
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));

    result[0] = 1;   // Carry will always be 1 in this problem
    for (int i = 0; i < digitsSize; i++) {
        result[i + 1] = digits[i];
    }

    *returnSize = digitsSize + 1;
    return result;
}
