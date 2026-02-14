/*
 Problem: Roman to Integer

 Approach:
 - Traverse the string from right to left.
 - Convert each Roman character to its integer value.
 - If the current value is smaller than the previous value, subtract it.
 - Otherwise, add it to the total sum.

 Time Complexity: O(n)
 Space Complexity: O(1)
*/

int romanToInt(char* s) {

    int sum = 0;
    int prev = 0;

    // Mapping Roman characters to integer values
    int values[256] = {0};
    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;

    for (int i = strlen(s) - 1; i >= 0; i--) {

        int curr = values[(unsigned char)s[i]];

        if (curr < prev) {
            sum -= curr;   // Subtract if smaller value before larger one
        } else {
            sum += curr;   // Otherwise, add
        }

        prev = curr;
    }

    return sum;
}
