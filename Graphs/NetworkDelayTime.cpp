class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &p : times){

            int s = p[0];
            int d = p[1];
            int dist = p[2];

            adj[s].push_back({d,dist});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int> ans(n+1, INT_MAX);
        
        ans[k] = 0;
        pq.push({0,k});

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

        int maxi = -1;
        for(int i=1;i<ans.size();i++){
            if(ans[i]==INT_MAX) return -1;
            else{
                maxi = max(ans[i],maxi);
            }
        }

        return maxi;
        
    }
};


/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.*/