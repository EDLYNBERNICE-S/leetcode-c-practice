/*
 Problem: Remove Duplicates from Sorted Array

 Description:
 Given a sorted array, remove the duplicates in-place such that
 each unique element appears only once.

 The function returns the number of unique elements (k).
 The first k elements of nums contain the result.

 Approach:
 - Use two pointers:
     - One pointer to track position of unique elements.
     - Another pointer to scan the array.
 - Copy only when a new unique element is found.

 Time Complexity: O(n)
 Space Complexity: O(1)
*/

int removeDuplicates(int* nums, int numsSize) {

    if (numsSize == 0) {
        return 0;
    }

    int k = 1;  // Index for placing unique elements

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
