/**
 * Backtracking and DFS
 * Not fast because too much copying going on. 
 * (Can solve with DSU?)
 * 
 **/


class Solution {
public:
    void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int currGold, int &maxGold, int i, int j, int rows, int cols, int dx[], int dy[]){
        if(i<0 || j<0 || i>=rows || j>=cols || visited[i][j]) return; //Boundary Conditions
        if(grid[i][j] == 0) return; // if cell is 0, do not explore. 
        visited[i][j] = true; // If not out of bounds mark or not visited mark as visited
        currGold += grid[i][j];
        for(int x=0; x<4; x++){
            dfs(grid, visited, currGold, maxGold, i+dx[x], j+dy[x], rows, cols, dx, dy);
        }
        visited[i][j] = false; //Backtracking
        maxGold = max(maxGold, currGold);
    }
    
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        //Right, down, left, up
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int maxGold = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]!=0){
                    dfs(grid, visited, 0, maxGold, i, j, row, col, dx, dy);
                }
            }
        }
        return maxGold;
        
    }
};