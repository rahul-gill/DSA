#include<cp_debug.h>

int dirx[8] = {1, 1,1,-1,-1,-1,0, 0};
int diry[8]=  {1,-1,0, 1,-1, 0,1,-1};

vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
    vector<vector<int>> positions;

    //loop through each starting position of the match
    for(int i=0; i<grid.size(); ++i) 
        for(int j=0; j<grid[i].size(); ++j)
            if(grid[i][j] == word[0])
                //if first character match check if the word matches in every directions
                for(int dirn = 0; dirn<8; ++dirn){
                    
                    int hlimit = j + (word.size()-1) * dirx[dirn]; 
                    int vlimit = i + (word.size()-1) * diry[dirn]; 
                    
                    if(hlimit >=0 && hlimit < grid[i].size() && vlimit >=0 && vlimit < grid.size()){
                        int ps = 1;
                        for(; ps<word.size(); ++ps){
                            int nextX = i + ps*diry[dirn], nextY = j + ps*dirx[dirn]; 
                            if(grid[nextX][nextY] != word[ps])
                                break;
                        }
                        if(ps == word.size()){
                            positions.push_back(vector<int>{i,j});
                            break;
                        }
                    }
                }
        
    return positions;

}
