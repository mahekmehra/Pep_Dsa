class Solution {
public:

    void solve(vector<vector<int>>& res, vector<int>& candidates, int target,int i,vector<int> temp){

        if(target==0){
            res.push_back(temp);
            return;
        }

        if(target<0 || i>=candidates.size()) return ;

        temp.push_back(candidates[i]);
        solve(res,candidates,target-candidates[i],i,temp);
        temp.pop_back();
        solve(res,candidates,target,i+1,temp);

    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> res;
        vector<int> temp;
        solve(res,candidates,target,0,temp);
        return res;
        
    }
};


/*Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
*/