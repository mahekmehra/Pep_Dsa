#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    vector<vector<int>> adj(v);
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    queue<int> q;
    vector<int> indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> res;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
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
    }

    return res;
}

/*Kahn's Algorithm
1> Calculate indegree of each node.
2> Add the node with indegree 0 to the queue.
3> Perform BFS :-
   -> while queue is empty,pop the front node, add to result vector and decrease its neighbour's indegree.
   -> if neighbour's indegree becomes 0 then add it to the queue.
4> return the result vector.*/