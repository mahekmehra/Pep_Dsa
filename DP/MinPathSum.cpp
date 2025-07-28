//Recursion

int solve(int i,int j,vector<vector<int>>& grid,int n,int m){


        if(i>=n || j>=m) return INT_MAX;

        if(i==n-1 && j==m-1) return grid[i][j];


        return grid[i][j] + min(solve(i+1,j,grid,n,m),solve(i,j+1,grid,n,m));
}

int minPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        return solve(0,0,grid,n,m);
        
}

//Memoization

int solve(int i, int j, vector<vector<int>>& grid, int n, int m,vector<vector<int>>&dp) {


        if (i >= n || j >= m) return INT_MAX;

        if (i == n - 1 && j == m - 1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        int down = solve(i+1,j,grid,n,m,dp);
        int left = solve(i,j+1,grid,n,m,dp);

        return dp[i][j] = grid[i][j] + min(down,left);
}

int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0, 0, grid, n, m,dp);
}

//Tabulation

int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0] = grid[0][0];
        for(int i=1;i<n;i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int j=1;j<m;j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
}

/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.*/
