/*
 Problem: Missing Number

 Approach:
 - The array contains numbers from 0 to n with one missing.
 - Compute the expected sum using the formula n * (n + 1) / 2.
 - Compute the actual sum of array elements.
 - The missing number is: expected_sum - actual_sum.

 Time Complexity: O(n)
 Space Complexity: O(1)
*/

int missingNumber(int* nums, int numsSize) {

    int expected_sum = numsSize * (numsSize + 1) / 2;
    int actual_sum = 0;

    for (int i = 0; i < numsSize; i++) {
        actual_sum += nums[i];
    }

    return expected_sum - actual_sum;
}
