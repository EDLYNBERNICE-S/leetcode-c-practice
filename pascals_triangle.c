/*
 Problem: Pascal's Triangle

 Description:
 Given an integer numRows, return the first numRows of Pascal's triangle.

 Each number is the sum of the two numbers directly above it.

 Example:
 Input: 5
 Output:
 [
   [1],
   [1,1],
   [1,2,1],
   [1,3,3,1],
   [1,4,6,4,1]
 ]

 Time Complexity: O(n^2)
 Space Complexity: O(n^2)
*/

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    if (numRows <= 0) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    // Allocate array of row pointers
    int **triangle = (int**)malloc(numRows * sizeof(int*));

    // Allocate column sizes array
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    *returnSize = numRows;

    for (int i = 0; i < numRows; i++) {

        // Allocate memory for each row
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        (*returnColumnSizes)[i] = i + 1;

        // First and last elements are always 1
        triangle[i][0] = 1;
        triangle[i][i] = 1;

        // Fill middle elements
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}
