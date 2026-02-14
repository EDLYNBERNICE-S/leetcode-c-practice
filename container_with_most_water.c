/*
 Problem: Container With Most Water (LeetCode)

 Description:
 Given an array of heights, find the maximum area of water a container can store.
 Two pointers are used to reduce time complexity from O(n^2) to O(n).

 Approach:
 - Initialize two pointers: one at the start and one at the end.
 - Compute the area formed by the lines at these pointers.
 - Move the pointer pointing to the shorter line inward.
 - Update maximum area found so far.

 Time Complexity: O(n)
 Space Complexity: O(1)
*/

int maxArea(int* height, int heightSize) {
    int leftPtr = 0;
    int rightPtr = heightSize - 1;
    int maxArea = 0;

    while (leftPtr < rightPtr) {

        int width = rightPtr - leftPtr;

        // Find the limiting height
        int minHeight;
        if (height[leftPtr] < height[rightPtr]) {
            minHeight = height[leftPtr];
            leftPtr++;    // Move left pointer inward
        } else {
            minHeight = height[rightPtr];
            rightPtr--;   // Move right pointer inward
        }

        int currentArea = width * minHeight;

        // Update maximum area if needed
        if (currentArea > maxArea) {
            maxArea = currentArea;
        }
    }

    return maxArea;
}
