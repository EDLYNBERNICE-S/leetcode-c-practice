/*
 Problem: Remove Element

 Description:
 Given an integer array nums and an integer val,
 remove all occurrences of val in-place.

 The order of elements may change.
 Return the number of elements not equal to val (k).

 The first k elements of nums should contain the result.

 Approach:
 - Use a pointer k to track the position of valid elements.
 - Iterate through the array.
 - Copy elements not equal to val to the front.

 Time Complexity: O(n)
 Space Complexity: O(1)
*/

int removeElement(int* nums, int numsSize, int val) {

    int k = 0;  // Position to place next valid element

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
