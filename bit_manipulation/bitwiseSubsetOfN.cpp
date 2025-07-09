

class Solution {
  public:
    vector<int> printSubsets(int n) {
        // Code here
        vector<int> res;
        for(int i=n;i>=0;i--){
            if((n&i)==i){
                res.push_back(i);
            }
        }
        
        return res;
    }
};

/*Input:
N = 5
Output: 5 4 1 0
Explanation:
   0 & 5 = 0
   1 & 5 = 1
   2 & 5 = 0
   3 & 5 = 1
   4 & 5 = 4
   5 & 5 = 5
*/
