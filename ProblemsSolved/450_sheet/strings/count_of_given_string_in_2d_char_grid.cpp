#include<cp_debug.h>

//this function is called for every character in matrix
int hSearch(int i, int j, vector<vector<char>> &mat, string target, int upto){
    int found = 0;
    
    //we go recursively in each direction and checking if the word is matched
    //also we put 0 in place of traversed characters so that we don't take the same character(same char at same place) twice
    //when returning from recursion, we put the original char value at its place
    if(i>=0 && j>=0 && i<mat.size() && j<mat[i].size() && mat[i][j] == target[upto]){
        char temp = target[upto];
        mat[i][j] = 0; //putting zero so that we don't make mistakes for words like 'ee'
        upto++;

        if(upto == target.size()){
            found = 1;
        }
        else{
            found += hSearch(i+1,j,mat,target,upto);
            found += hSearch(i-1,j,mat,target,upto);
            found += hSearch(i,j+1,mat,target,upto);
            found += hSearch(i,j-1,mat,target,upto);
        }
        mat[i][j] = temp; //put original character at its location   
    }
    return found;
}


int findOccurrence(vector<vector<char> > &mat, string target){
    int ans = 0;

    for(int i=0; i<mat.size(); i++)
        for(int j=0; j<mat[i].size(); j++){
            ans += hSearch(i,j, mat, target, 0);
        }
    return ans;
}

