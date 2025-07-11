class Solution {
public:

    void solve(vector<vector<int>>& res,vector<int>& nums,vector<int>& temp,int i){

        if(i==nums.size()){
            res.push_back({temp});
            return;
        }

        temp.push_back(nums[i]);

        solve(res,nums,temp,i+1);

        temp.pop_back();
        int idx = i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;

        solve(res,nums,temp,idx);

    }



    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(res,nums,temp,0);
        return res;
        
    }
};

/*Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]  no duplicate subsets allowed
*/