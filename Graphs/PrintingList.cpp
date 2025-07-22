vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>> res(n);
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        res[u].push_back(v);
        res[v].push_back(u);
    }

    vector<vector<int>> ans(n);
    for(int i=0;i<n;i++){
        ans[i].push_back(i);

        for(int &j : res[i]){
            ans[i].push_back(j);
        }
    }

    return ans;
}

/* if adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
then output should be = [[0,1,2,3],[1,0],[2,0,4],[3,0],[4,2]]
(include the node with its neighbour)*/