#include<bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > matrix, int rowEnd, int colEnd) {
    vector<int> ans;
    int i, rowStart = 0, colStart = 0;

    while (rowStart < rowEnd && colStart < colEnd) {
        /* Print the first row from the remaining rows */
        for (i = colStart; i < colEnd; ++i)  
            ans.push_back(matrix[rowStart][i]);
        rowStart++;

        /* Print the last column from the remaining columns */
        for (i = rowStart; i < rowEnd; ++i) 
            ans.push_back(matrix[i][colEnd - 1]);
        colEnd--;

        /* Print the last row from the remaining rows */
        if (rowStart < rowEnd) {
            for (i = colEnd - 1; i >= colStart; --i) 
                ans.push_back(matrix[rowEnd - 1][i]);
            rowEnd--;
        }

        /* Print the first column from the remaining columns */
        if (colStart < colEnd) {
            for (i = rowEnd - 1; i >= rowStart; --i) 
                ans.push_back(matrix[i][colStart]);
            colStart++;
        }
    }
    return ans;
}
