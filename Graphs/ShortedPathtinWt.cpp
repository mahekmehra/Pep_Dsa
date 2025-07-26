
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &p : edges){
            int s = p[0];
            int d = p[1];
            int dist = p[2];
            
            adj[s].push_back({d,dist});
            adj[d].push_back({s,dist});
        }
        
        int src = 1, dest = n;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> ans(n+1, INT_MAX);
        vector<int> parent(n+1,-1);
        
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
                    parent[neighbour] = node;
                }
            }
            
        }
        
        vector<int> res;
        if(ans[dest]==INT_MAX){
            return {-1};
        }
        
        while(src!=dest){
            res.push_back(dest);
            dest = parent[dest];
        }
        
        res.push_back(src);
        int total_weight = ans[n];
        res.push_back(total_weight);
        reverse(res.begin(),res.end());
        return res;
        
        
    }
};

/*You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

Examples :

Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
Input: n = 2, m= 1, edges = [[1, 2, 2]]
Output: 2
Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 
*/