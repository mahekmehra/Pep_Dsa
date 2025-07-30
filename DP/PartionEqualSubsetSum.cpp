
//Tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = 0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2!=0) return false;
        int n = nums.size();
        int target = sum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,false));

        for(int i=0;i<n+1;i++){
            dp[i][0] = true;
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
        
    }
};

//Memoization

class Solution {
public:

    bool solve(vector<int>& nums, int sum,vector<vector<int>>&dp,int n){
        
        if(sum==0) return true;
        
        if(n==0) return false;
        
        if(dp[n][sum] != -1) return dp[n][sum];
        
        if(nums[n-1]<=sum){
            dp[n][sum] = solve(nums,sum-nums[n-1],dp,n-1) || solve(nums,sum,dp,n-1);
        }else{
            dp[n][sum] = solve(nums,sum,dp,n-1);
        } 
        return dp[n][sum];
        
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(nums,target,dp,n);
        
    }
};


/*Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].*/