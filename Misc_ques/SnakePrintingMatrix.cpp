
class Solution {
  public:
    vector<int> snakePattern(vector<vector<int> > matrix) {
        // code here   
        int n = matrix.size();
        int ur = 0;
        vector<int> res;
        
        while(ur<=n-1){
            
            for(int i=0;i<=n-1;i++){
                res.push_back(matrix[ur][i]);
            }
            ur++;
            
            if(ur<=n-1){
                for(int i=n-1;i>=0;i--){
                    res.push_back(matrix[ur][i]);
                }
                ur++;
            }
        }
        
        return res;
    }
};

/*Input: n = 3, mat[][] = [[45, 48, 54], [21, 89, 87], [70, 78, 15]]
Output: [45, 48, 54, 87, 89, 21, 70, 78, 15] 
Explanation: Printing it in snake pattern will lead to the output as [45, 48, 54, 87, 89, 21, 70, 78, 15] 
.
Input: n = 2, mat[][] = [[1, 2], [3, 4]]
Output: [1, 2, 4, 3] 
Explanation: Printing it in snake pattern will give output as [1, 2, 4, 3]..*/