
//Memoization

class Solution {
public:

    int solve(int n,vector<int> &dp){

        if(n<=1) return 1;

        if(dp[n]!=-1) return dp[n];

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);


    }

    int climbStairs(int n) {

        if(n<=1) return 1;

        vector<int> dp(n+1,-1);

        return solve(n,dp);
        
    }
};


//2nd approach (Tabulation)

int climbStairs(int n) {

        if(n<=1) return 1;

        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
        
}

/*You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps*/