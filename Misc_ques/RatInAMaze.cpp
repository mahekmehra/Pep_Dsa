
class Solution {
  public:
  
  
    void solve(vector<vector<int>>& maze,vector<string> &res,string temp,int r,int c){
        
        int n = maze.size();
        
        if(r<0 || c<0 || r>=n || c >=n || maze[r][c]==0 || maze[r][c] == -1) return;
        
        if(r==n-1 && c==n-1){
            res.push_back(temp);
            return;
        }
        
        maze[r][c] = -1;
        
        solve(maze,res,temp+"D",r+1,c);
        solve(maze,res,temp+"L",r,c-1);
        solve(maze,res,temp+"R",r,c+1);
        solve(maze,res,temp+"U",r-1,c);
        
        maze[r][c] = 1;
    }
  
  
  
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> res;
        string temp = "";
        solve(maze,res,temp,0,0);
        return res;
    }
};

/*Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.

Examples:

Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell is blocked.*/