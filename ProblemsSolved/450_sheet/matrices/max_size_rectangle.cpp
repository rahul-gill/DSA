#include<bits/stdc++.h>
using namespace std;

/**
 * Given a binary matrix M of size n X m. 
 * Find the maximum area of a rectangle formed only of 1s in the given matrix. 
 * Idea: apply the max area rectangle on histogram algorithm on each row of matrix
 */

#define MAX 1000


int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n),right(n);
    
    stack<int> mystack;
    for(int i=0;i<n;++i)    //Fill left
    {
        if(mystack.empty())
        {    left[i] = 0;   mystack.push(i);    }
        else
        {
            while(!mystack.empty() and heights[mystack.top()]>=heights[i])
                mystack.pop();
            left[i] = mystack.empty()?0:mystack.top()+1;
            mystack.push(i);
        }
    }
    while(!mystack.empty()) //Clear stack
        mystack.pop();
    
    for(int i=n-1;i>=0;--i) //Fill right
    {
        if(mystack.empty())
        {   right[i] = n-1; mystack.push(i);    }
        else
        {
            while(!mystack.empty() and heights[mystack.top()]>=heights[i])
                mystack.pop();
            right[i] = mystack.empty()?n-1:mystack.top()-1;
            mystack.push(i);
        }
    }
    int mx_area = 0;    //Stores max_area
    for(int i=0;i<n;++i)
        mx_area = max(mx_area,heights[i]*(right[i]-left[i]+1));
    return mx_area;
}




int maxAreaRow(int row[MAX], int m){
    vector<int> left(m),right(m);    
    stack<int> stk;


    for(int i=0; i<m; i++){
        if(stk.empty()){
            left[i] = 0;
        }
        else{ 
            while(!stk.empty() and row[stk.top()] >= row[i])
                stk.pop();
            left[i] = stk.empty() ? 0 : stk.top()+1;
        }
        stk.push(i);
    }
    
    while(!stk.empty()) 
        stk.pop();

    for(int i=m-1; i>=0; i--){
        if(stk.empty())
            right[i] = m-1;
        else{ 
            while(!stk.empty() and row[stk.top()] >= row[i])
                stk.pop();
            right[i] = stk.empty() ? m-1 : stk.top()-1;
        }
        stk.push(i);
    }

    int maxV = INT_MIN;
    for(int i=0; i<m; i++){
        maxV = max(maxV, row[i] * (right[i] - left[i] + 1));
    }

    cout<<"left: ";
    for(const int &x: left) cout<<x<<' '; cout<<'\n';
    cout<<"right: ";
    for(const int &x: right) cout<<x<<' '; cout<<'\n';

    cout<<"ans: "<<maxV<<'\n';

    return maxV;
}

int maxArea(int M[MAX][MAX], int n, int m) {
    int maxV = INT_MIN;
    
    for(int i=1; i<n; i++)
        for(int j=0; j<m; j++){
            if(M[i][j] != 0)
                M[i][j] += M[i-1][j];
        }
    

    for(int i=0; i<n; i++)
        maxV = max(maxV, maxAreaRow(M[i], m));
    
    return maxV;
}

int main(){
    int a[3] = {1,2,3};
    maxAreaRow(a, 3);
}
