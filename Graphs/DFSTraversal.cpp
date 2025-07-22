    void dfs(vector<vector<int>>& adj,int u,vector<bool> &visited,vector<int> &ans){
        
        if(visited[u]==true) return;
        
        ans.push_back(u);
        visited[u]=true;
        
        for(int &v : adj[u]){
            if(!visited[v]){
                dfs(adj,v,visited,ans);
            }
        }
    }
  
  
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<bool> visited(n,false);
        dfs(adj,0,visited,ans);
        return ans;
    }


    /*Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output: [0, 2, 4, 3, 1]
Explanation: Starting from 0, the DFS traversal proceeds as follows:
Visit 0 → Output: 0 
Visit 2 (the first neighbor of 0) → Output: 0, 2 
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1*/