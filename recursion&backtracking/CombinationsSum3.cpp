
class Solution {
public:

    void solve(vector<vector<int>> &res,vector<int> &temp,int k,int target,int idx){

        if(target==0 && k==0){
            res.push_back(temp);
            return;   
        }

        for(int i=idx;i<=9;i++){

            if(k==0) break;
            if(i>target) break;
            
            temp.push_back(i);
            solve(res,temp,k-1,target-i,i+1);
            temp.pop_back();

        }
    }



    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> res;
        vector<int> temp;
        solve(res,temp,k,n,1);
        return res;
    }
};



/*Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
*/