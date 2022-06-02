#include<cp_debug.h>

vector<vector<char>> grid;
string word;

int dirx[8] = {1, 1,1,-1,-1,-1,0, 0};
int diry[8]=  {1,-1,0, 1,-1, 0,1,-1};

pair<int,int> move_in_dir(int i, int j, int steps, int direction_n){
    return { i + steps * diry[direction_n], j + steps* dirx[direction_n] };
}

bool check_for_limits(int i, int j, int dirn){
    int hlimit, vlimit;
    tie(vlimit, hlimit) = move_in_dir(i, j, word.size()-1, dirn);
    bool h_limit_ok = hlimit >=0 && hlimit < grid[i].size();
    bool v_limit_ok =  vlimit >=0 && vlimit < grid.size(); 
    return h_limit_ok && v_limit_ok;
}

bool check_eq(int i, int j, int dirn){
    int step_n = 1, nextX, nextY;
    //take steps and match the word characters
    for(; step_n<word.size(); ++step_n){
        tie(nextX, nextY) = move_in_dir(i, j, step_n, dirn);
        if(grid[nextX][nextY] != word[step_n])
            break;
    }
    return step_n == word.size();
}

vector<vector<int>>searchWord(vector<vector<char>>grid_arg, string word_arg){
    grid = grid_arg;
    word = word_arg;
    vector<vector<int>> positions;

    for(int i=0; i<grid.size(); ++i) 
        for(int j=0; j<grid[i].size(); ++j)
            if(grid[i][j] == word[0])
                for(int dirn = 0; dirn<8; ++dirn)
                    if(check_for_limits(i,j,dirn) && check_eq(i,j,dirn)){
                        positions.push_back(vector<int>{i,j});
                        break;
                    }

    return positions;
}
