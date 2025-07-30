
//Recursive

class Solution {
  public:
  
    int solve(int W, vector<int> &val, vector<int> &wt,int n){
        
        if(W==0 || n==0) return 0;
        
        if(wt[n-1]<=W){
            return max((val[n-1]+solve(W-wt[n-1],val,wt,n-1)),solve(W,val,wt,n-1));
        }else{
            return solve(W,val,wt,n-1);
        }
    }
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        return solve(W,val,wt,n);
    }
};

//Memoization

class Solution {
  public:
  
    int solve(int W, vector<int> &val, vector<int> &wt,int n,vector<vector<int>> &dp){
        
        if(W==0 || n==0) return 0;
        
        if(dp[n][W]!=-1){
            return dp[n][W];
        }
        
        if(wt[n-1]<=W){
            dp[n][W] = max((val[n-1]+solve(W-wt[n-1],val,wt,n-1,dp)),solve(W,val,wt,n-1,dp));
        }else{
            dp[n][W] = solve(W,val,wt,n-1,dp);
        }
        
        return dp[n][W];
    }
  
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solve(W,val,wt,n,dp);
    }
};


//Tabulation

int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = wt.size();
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<W+1;j++){
                if(wt[i-1]<=j){
                    dp[i][j] = max((val[i-1]+dp[i-1][j-wt[i-1]]),dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][W];
}