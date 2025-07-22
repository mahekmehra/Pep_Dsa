
class Solution {
public:

    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>> &visited){

        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]!='1' || visited[i][j]) return;


        visited[i][j] = true;
        dfs(i+1,j,grid,visited);
        dfs(i-1,j,grid,visited);
        dfs(i,j-1,grid,visited);
        dfs(i,j+1,grid,visited);

    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();

        int count = 0;

        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }
        return count;
        
    }
};



/*Note :- We can make the grid value as '0' where we have visited instead of using the visited grid !!!


Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3*/