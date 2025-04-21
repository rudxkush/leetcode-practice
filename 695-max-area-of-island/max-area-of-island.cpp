class Solution {
public:
    int maxArea = 0;
    void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) 
            return ;

        grid[i][j] = 0;
        area++;
        maxArea = max(maxArea, area);
        dfs(grid, i - 1, j, area); // up
        dfs(grid, i + 1, j, area); // down
        dfs(grid, i, j + 1, area); // right
        dfs(grid, i, j - 1, area); // left
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    dfs(grid, i, j, area);
                }
            }
        }
        return maxArea;
    }
};