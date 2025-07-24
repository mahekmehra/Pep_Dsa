
//dfs approach


void dfs(int i,int j,vector<vector<char>>& mat,vector<vector<bool>> &visited){
        
        if(i<0 || i>=mat.size()|| j<0 || j>=mat[0].size() || mat[i][j]=='X'|| visited[i][j]) return;
        
        visited[i][j] = true;
        
        dfs(i-1,j,mat,visited);
        dfs(i+1,j,mat,visited);
        dfs(i,j-1,mat,visited);
        dfs(i,j+1,mat,visited);
}
  
vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        
        //first column && last column
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' && !visited[0][j]){
                dfs(0,j,mat,visited);
            }
            
            if(mat[n-1][j]=='O' && !visited[n-1][j]){
                dfs(n-1,j,mat,visited);
            }
        }
        
        //first row && last row
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !visited[i][0]){
                dfs(i,0,mat,visited);
            }
            
            if(mat[i][m-1]=='O' && !visited[i][m-1]){
                dfs(i,m-1,mat,visited);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='O' && !visited[i][j]){
                    mat[i][j]='X';
                }
            }
        }
        
        return mat;
}

/*Given a matrix mat where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.

Examples:

Input: mat = 
[['X', 'X', 'X', 'X'], 
['X', 'O', 'X', 'X'], 
['X', 'O', 'O', 'X'], 
['X', 'O', 'X', 'X'], 
['X', 'X', 'O', 'O']]
Output: 
[['X', 'X', 'X', 'X'], 
['X', 'X', 'X', 'X'], 
['X', 'X', 'X', 'X'], 
['X', 'X', 'X', 'X'], 
['X', 'X', 'O', 'O']]
Explanation: We only changed those 'O' that are surrounded by 'X'*/