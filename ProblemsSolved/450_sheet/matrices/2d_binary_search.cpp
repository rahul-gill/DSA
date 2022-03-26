#include<bits/stdc++.h>
using namespace std;

/**
 * Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix.
 * This matrix has the following properties:
 *   Integers in each row are sorted from left to right.
 *   The first integer of each row is greater than the last integer of the previous row.
 *
 */
bool search(vector<vector<int>> grid, int targetValue) {
    int rows = grid.size();
    int cols = grid[0].size();

    int leftBound = 0;
    int rightBound = rows * cols - 1;


    while (true) {
        int currentIndex = (leftBound + rightBound) / 2;
        
        int currentRow = currentIndex / cols;
        int currentColumn = currentIndex % cols;
        int currentValue = grid[currentRow][currentColumn];

        if (currentValue == targetValue) 
            return true;
        else if (rightBound <= leftBound) 
            return false;
        else if (currentValue < targetValue)
            leftBound = currentIndex + 1;
        else
            rightBound = currentIndex - 1;

    }

}
