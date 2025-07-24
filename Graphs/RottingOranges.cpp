bool make(int i,int j,vector<vector<int>>& grid){

        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()|| grid[i][j]!=1) return false;

        grid[i][j]=2;
        return true;
}



int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

    // Step 1: Find initial rotten oranges and count fresh ones
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }

        if(fresh == 0) return 0;  // No fresh oranges to begin with

        int minutes = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int sz = q.size();
            bool rotted = false;
            while(sz--){
                auto [i, j] = q.front(); q.pop();

                for(int d = 0; d < 4; ++d){
                    int ni = i + dirs[d][0];
                    int nj = j + dirs[d][1];
                    if(make(ni, nj, grid)){
                        q.push({ni, nj});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if(rotted) minutes++;
        }
        return fresh == 0 ? minutes : -1;
        
}

//approach 2

bool make(int i, int j, vector<vector<int>>& grid) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
        return false;

    grid[i][j] = 3; // mark to rot in next minute
    return true;
}

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int minutes = 0;

    while (true) {
        bool changed = false;

        // mark new oranges to rot (with 3 temporarily)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    bool down = make(i + 1, j, grid);
                    bool up = make(i - 1, j, grid);
                    bool left = make(i, j - 1, grid);
                    bool right = make(i, j + 1, grid);
                    if (down || up || left || right) changed = true;
                }
            }
        }

        // update all newly rotten oranges to 2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 3) grid[i][j] = 2;
            }
        }

        if (!changed) break; // no new oranges rotted in this minute
        minutes++;
    }

    // check if any fresh orange remains
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) return -1;
        }
    }

    return minutes;
}
