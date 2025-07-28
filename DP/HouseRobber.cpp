
//Memoization
class Solution {
public:

    int solve(int i,vector<int>& nums,vector<int>& dp){

        if(i>=nums.size()) return 0;

        if(dp[i]!=-1) return dp[i];

        int take = nums[i] + solve(i+2,nums,dp);
        int skip = solve(i+1,nums,dp);
            
        return dp[i] = max(take,skip);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,-1);
        return solve(0,nums,dp);
        
    }
};

//Tabular form

class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int take = nums[i] + dp[i-2];
            int skip = dp[i-1];
            dp[i]=max(take,skip);
        }
        return dp[n-1];
        
    }
};



/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).*/