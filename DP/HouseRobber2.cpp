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
        vector<int>nums1,nums2;
        vector<int> dp1(n,-1),dp2(n,-1);
        for(int i=0;i<n-1;i++){
            nums1.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            nums2.push_back(nums[i]);
        }
        return max(solve(0,nums1,dp1),solve(0,nums2,dp2));
    }
};

//Tabulation

class Solution {
public:

    int solve(vector<int>& nums,vector<int>& dp){

        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int take = nums[i] + dp[i-2];
            int skip = dp[i-1];
            dp[i]=max(take,skip);
        }
        return dp[n-1];

    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1);
        vector<int> nums1(nums.begin(),nums.end()-1); //excluding the last element
        vector<int> nums2(nums.begin()+1,nums.end()); //excluding the first element

        //size must be n-1 because 0 to n-2 or 1 to n-1 , the size of array will be n-1
        vector<int> dp1(n-1,0),dp2(n-1,0);

        return max(solve(nums1,dp1),solve(nums2,dp2));
        
        
    }
};