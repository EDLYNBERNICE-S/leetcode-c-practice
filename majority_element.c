#include <stdio.h>

/*
 Problem: Majority Element

 Description:
 Find the element that appears more than ⌊n/2⌋ times.

 Approach:
 - Use Boyer–Moore Voting Algorithm.
 - Maintain a candidate and a counter.
 - If count becomes 0, select a new candidate.
 - Increase count if element matches candidate.
 - Decrease count otherwise.
 - (Optional) Verify the candidate.

 Time Complexity: O(n)
 Space Complexity: O(1)
*/

int majorityElement(int* nums, int numsSize) {

    int candidate = 0;
    int count = 0;

    // Step 1: Find potential candidate
    for (int i = 0; i < numsSize; i++) {

        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } 
        else if (nums[i] == candidate) {
            count++;
        } 
        else {
            count--;
        }
    }

    // Step 2: Optional verification (if majority not guaranteed)
    int occurrences = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) {
            occurrences++;
        }
    }

    return (occurrences > numsSize / 2) ? candidate : -1;
}
