/*
 Problem: Search Insert Position

 Description:
 Given a sorted array of distinct integers and a target value,
 return the index if the target is found.
 If not, return the index where it would be inserted.

 Approach:
 - Traverse array
 - If element equals target → return index
 - If element greater than target → return index
 - If not found → return numsSize

 Time Complexity: O(n)
 Space Complexity: O(1)
*/

int searchInsert(int* nums, int numsSize, int target) {

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= target) {
            return i;
        }
    }

    return numsSize;
}
