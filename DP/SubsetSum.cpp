
//Tabulation

class Solution {
  public:
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,false));
        
        for(int j=0;j<n+1;j++){
            dp[j][0] = true;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};

//Tabulation

class Solution {
  public:
  
    bool solve(vector<int>& arr, int sum,vector<vector<bool>>&dp,int n){
        
        if(sum==0) return true;
        
        if(n==0) return false;
        
        if(dp[n][sum] != false) return dp[n][sum];
        
        if(arr[n-1]<=sum){
            dp[n][sum] = solve(arr,sum-arr[n-1],dp,n-1) || solve(arr,sum,dp,n-1);
        }else{
            dp[n][sum] = solve(arr,sum,dp,n-1);
        }
        
        return dp[n][sum];
        
    }
  
  
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
        return solve(arr,sum,dp,n);
        
    }
};

/*Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.*/