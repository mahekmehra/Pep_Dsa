//dfs approach


class Solution {
  public:
  
  
    bool dfs(vector<bool> &visited,vector<bool> &recurse,vector<vector<int>> &adj,int u){
        
        visited[u] = true;
        recurse[u] = true;
        for(int &v : adj[u]){
            
            if(!visited[v] && dfs(visited,recurse,adj,v)){
                return true;
            }else if(recurse[v]==true){
                return true;
            }
        }
        recurse[u] = false;
        return false;
        
    }
  
    
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V,false);
        vector<bool> recurse(V,false);
        
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(visited,recurse,adj,i)){
                return true;
            }
        }
        return false;
        
        
    }
};


//bfs approach  (Kahn's algorithm)

bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        queue<int> q;
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }

        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> res;
        while(!q.empty()){
            int n = q.front();
            res.push_back(n);
            q.pop();
            for(int &v : adj[n]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        
        if(res.size()!=V) return true;
        else return false;
}