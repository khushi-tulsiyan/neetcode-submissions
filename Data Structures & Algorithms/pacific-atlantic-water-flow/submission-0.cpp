class Solution {
public:
    vector<vector<int>> res;
    vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));


        for(int i = 0;i<cols; i++){
            dfs(0, i, pac, heights);
            dfs(rows-1, i, atl, heights);
        }

        for(int j = 0; j<rows; j++){
            dfs(j, 0, pac, heights);
            dfs(j, cols-1, atl, heights);
        }
        for(int i = 0; i<rows; i++){
            for(int j = 0; j<cols; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    private: 
    void dfs(int i, int j, vector<vector<bool>> &ocean, vector<vector<int>> &heights){
        ocean[i][j] = true;
        for(auto [dr, dc] : directions){
            int nr = i+dr, nc = j+dc;
            if(nr >= 0 && nc >= 0 && nr < heights.size() && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[i][j]){
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};