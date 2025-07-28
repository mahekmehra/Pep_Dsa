class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans;
        int lc=0;
        int rc=col-1;
        int ur=0;
        int br=row-1;
        while(ur<=br && lc<=rc){
            for(int i=lc;i<=rc;i++){
                ans.push_back(matrix[ur][i]);
            }
            ur++;
        
            for(int i=ur;i<=br;i++){
                ans.push_back(matrix[i][rc]);
            }
            rc--;

            if(ur<=br){
                for(int i=rc;i>=lc;i--){
                    ans.push_back(matrix[br][i]);
                }
                br--;
            }

            if(lc<=rc){
                for(int i=br;i>=ur;i--){
                    ans.push_back(matrix[i][lc]);
                }
                lc++;

            }  
        }
        return ans;
        
    }
};


/*Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]*/