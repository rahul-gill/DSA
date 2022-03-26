#include <bits/stdc++.h>
using namespace std;

/**
 * Given a row wise sorted matrix of size RxC where R and C are always odd, find the median of the matrix.
 */


class Solution{
public:
    int binaryMedian(vector<vector<int>> matrix, int r ,int c){
        int minV = INT_MAX, maxV = INT_MIN;
        for(auto row: matrix){
            minV = min(row[0], minV);
            maxV = max(row.back(), maxV);
        }

        int desired = (r * c + 1) / 2;

        while (minV < maxV){
            int mid = minV + (maxV - minV) / 2;
            int place = 0;
            // Find count of elements smaller than mid
            for (int i = 0; i < r; ++i)
                place += upper_bound(matrix[i].begin(), matrix[i].begin()+c, mid) - matrix[i].begin();

            if (place < desired)
                minV = mid + 1;
            else
                maxV = mid;
        }
        return minV;
    }

};
