/*
 Problem: Valid Parentheses

 Approach:
 - Use a stack to store the expected closing brackets.
 - When an opening bracket is found, push its matching closing bracket.
 - When a closing bracket is found:
     - Check if the stack is empty or top doesn't match.
     - If mismatch, return false.
 - At the end, if stack is empty, parentheses are valid.

 Time Complexity: O(n)
 Space Complexity: O(n)
*/

bool isValid(char* s) {

    int len = strlen(s);

    // Stack to store expected closing brackets
    char *stack = (char *)malloc(len * sizeof(char));
    int top = 0;

    for (int i = 0; i < len; i++) {

        if (s[i] == '(') {
            stack[top++] = ')';
        } 
        else if (s[i] == '[') {
            stack[top++] = ']';
        } 
        else if (s[i] == '{') {
            stack[top++] = '}';
        } 
        else {
            // Closing bracket case
            if (top == 0 || stack[top - 1] != s[i]) {
                free(stack);
                return false;
            }
            top--;
        }
    }

    bool isValid = (top == 0);
    free(stack);
    return isValid;
}
