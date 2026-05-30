class Solution {
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>> &grid, int i, int j){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0'){
            return;
        }
        grid[i][j] = '0';
        for(int g = 0; g<4; g++){
            dfs(grid, i+directions[g][0], j+directions[g][1]);
        }
    }

};
