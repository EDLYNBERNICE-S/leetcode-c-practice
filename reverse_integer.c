/*
 Problem: Reverse Integer

 Approach:
 - Extract digits one by one using modulo.
 - Build the reversed number.
 - Before updating the result, check for 32-bit integer overflow.
 - If overflow occurs, return 0.

 Time Complexity: O(log10(n))
 Space Complexity: O(1)
*/

int reverse(int x) {

    int result = 0;

    while (x != 0) {

        int digit = x % 10;
        x = x / 10;

        // Check for overflow before multiplying by 10
        if (result > INT_MAX / 10 || 
           (result == INT_MAX / 10 && digit > 7)) {
            return 0;
        }

        // Check for underflow
        if (result < INT_MIN / 10 || 
           (result == INT_MIN / 10 && digit < -8)) {
            return 0;
        }

        result = result * 10 + digit;
    }

    return result;
}
