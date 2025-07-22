
void dfs(vector<vector<int>>& adj,int u,vector<bool> &visited){

        if(visited[u]==true) return;

        visited[u] = true;
        for(int &v : adj[u]){
            dfs(adj,v,visited);
        }
}


int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int count = 0;
        vector<bool> visited(n,false);

        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                count++;
            }
        }

        return count;

}


/*There is an undirected graph with n nodes. There is also an edges array, where edges[i] = [a, b] means that there is an edge between node a and node b in the graph.

The nodes are numbered from 0 to n - 1.

Return the total number of connected components in that graph.

Example 1:

Input:
n=3
edges=[[0,1], [0,2]]

Output:
1*/