class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V = adj.size();
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> ans(V, INT_MAX);
        
        ans[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &v : adj[node]){
                int neighbour = v;
                int ndist = 1;
                if(dist + ndist < ans[neighbour]){
                    ans[neighbour] = dist+ndist;
                    pq.push({dist+ndist,neighbour});
                }
            }
        }
        
        for(int i=0;i<V;i++){
            if(ans[i]==INT_MAX){
                ans[i] = -1;
            }
        }
        
        return ans;
        
        
    }
};

/*You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Examples :

Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]*/