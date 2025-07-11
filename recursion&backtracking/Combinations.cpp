

 void solve(vector<vector<int>> &res,vector<int> &temp,int n,int k,int start){

        if(k==0){
            res.push_back(temp);
            return;
        }

        if(start>n) return;

        temp.push_back(start);
        solve(res,temp,n,k-1,start+1);
        temp.pop_back();
        solve(res,temp,n,k,start+1);

    }


    vector<vector<int>> combine(int n, int k) {

        vector<vector<int>> res;
        vector<int> temp;
        solve(res,temp,n,k,1);
        return res;
        
    }
}






/*Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.*/