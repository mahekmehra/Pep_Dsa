    
    void bfs(vector<vector<int>> &adj,int u,vector<bool> &visited,vector<int> &ans){
        
        queue<int> q;
        q.push(u);
        visited[u]=true;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int &v : adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    
    
    
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        int n = adj.size();
        
        vector<bool> visited(n,false);
        bfs(adj,0,visited,ans);
        return ans;
    }


    /*Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output: [0, 2, 3, 1, 4]
Explanation: Starting from 0, the BFS traversal will follow these steps: 
Visit 0 → Output: 0 
Visit 2 (first neighbor of 0) → Output: 0, 2 
Visit 3 (next neighbor of 0) → Output: 0, 2, 3 
Visit 1 (next neighbor of 0) → Output: 0, 2, 3, 
Visit 4 (neighbor of 2) → Final Output: 0, 2, 3, 1, 4*/