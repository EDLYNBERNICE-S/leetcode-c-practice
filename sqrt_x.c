/*
 Problem: Sqrt(x)

 Approach:
 - Use Binary Search between 2 and x/2.
 - For each mid, compare mid*mid with x.
 - If square == x, return mid.
 - If square < x, move left boundary.
 - If square > x, move right boundary.
 - When loop ends, right will contain the integer square root.

 Time Complexity: O(log n)
 Space Complexity: O(1)
*/

int mySqrt(int x) {

    if (x < 2) {
        return x;
    }

    long long left = 2;
    long long right = x / 2;

    while (left <= right) {

        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == x) {
            return (int)mid;
        } 
        else if (square < x) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    // right will be the integer part of sqrt(x)
    return (int)right;
}
