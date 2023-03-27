class Solution {
  int solve(vector<vector<int>> &grid,int row, int col, int i, int j,vector<vector<int>> &dp){
        //base case 
        
        if(i==row-1 && j==col-1){
            return grid[i][j];
        }
        if(i>=row || j>=col){
            return INT_MAX; 
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        //recusrive call
        int x = solve(grid,row,col,i+1,j,dp);
        int y = solve(grid,row,col,i,j+1,dp);
        
        //small calculation for recursion
        int ans = min(x,y) + grid[i][j];
        dp[i][j] = ans;
        return ans;
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int given_row = grid.size();
        int given_col = grid[0].size();
        //int ans = INT_MAX;
        vector<vector<int>> dp(given_row, vector<int>(given_col,-1));
        return solve(grid,given_row,given_col,0,0,dp);
    }
};
