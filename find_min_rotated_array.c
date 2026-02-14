/*
 Problem: Find Minimum in Rotated Sorted Array

 Description:
 An array originally sorted in ascending order is rotated.
 Find the minimum element in O(log n) time.

 Approach:
 - Use Binary Search.
 - If nums[mid] > nums[right], the minimum lies in the right half.
 - Else, the minimum lies in the left half (including mid).

 Time Complexity: O(log n)
 Space Complexity: O(1)
*/

int findMin(int* nums, int numsSize) {

    int left = 0;
    int right = numsSize - 1;

    while (left < right) {

        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // Minimum is in right half
            left = mid + 1;
        } else {
            // Minimum is in left half (including mid)
            right = mid;
        }
    }

    return nums[left];
}
