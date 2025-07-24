
bool bfs(vector<vector<int>> &adj,int u,vector<bool> &visited){
        
        queue<pair<int,int>> q;
        
        q.push({u,-1});
        visited[u]=true;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int node = p.first;
            int parent = p.second;
            
            for(int &v : adj[node]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push({v,node});
                }else if(v!=parent){
                    return true;
                }
            }
        }
        return false;
    }
  
  
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] && bfs(adj,i,visited)){
                return true;
            }
        }
        
        return false;
    }



    /* (Main condition using bfs and dfs)
    1> If the node is visited
    2> and it is not the parent of adjacent node*/

    // (approach 2 using dfs)

    bool dfs(vector<vector<int>> &adj,int u,vector<bool> &visited,int parent){
        
        visited[u] = true;
        for(int &v : adj[u]){
            if(!visited[v]){
                if(dfs(adj,v,visited,u)){
                    return true;
                }            
            }
            else if(visited[v] && parent!=v){
                return true;
            }
        }
        return false;
    }
  
  
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(adj,i,visited,-1)){
                return true;
            }
        }
        
        return false;
    }

/*Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.*/