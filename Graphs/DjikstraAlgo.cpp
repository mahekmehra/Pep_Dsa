
class Solution {
  public:
  
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adj(V);
        for(auto &p : edges){
            int s = p[0];
            int d = p[1];
            int dist = p[2];
            
            adj[s].push_back({d,dist});
            adj[d].push_back({s,dist});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> ans(V, INT_MAX);
        
        ans[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &pair : adj[node]){
                int neighbour = pair.first;
                int ndist = pair.second;
                if(dist + ndist < ans[neighbour]){
                    ans[neighbour] = dist+ndist;
                    pq.push({dist+ndist,neighbour});
                }
            }
            
        }
        
        return ans;
        
    }
};


/*Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.

Examples:

Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
Explanation:

Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2*/