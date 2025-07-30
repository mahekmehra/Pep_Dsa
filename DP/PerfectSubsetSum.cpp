


class Solution {
  public:
  
  
    int solve(vector<int>& arr,int n,int target,vector<vector<int>>&dp){
        
        if(n==0){
            return target==0? 1:0;
        }
        
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        if(arr[n-1]<=target){
            dp[n][target] = solve(arr,n-1,target-arr[n-1],dp) + solve(arr,n-1,target,dp);
        }else{
            dp[n][target] = solve(arr,n-1,target,dp);
        }
        
        return dp[n][target];
    }
  
  
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(arr,n,target,dp);
        
    }
};