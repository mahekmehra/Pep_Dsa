
void bfs(queue<pair<int,int>> &q,vector<vector<bool>> &visited,vector<vector<char>>& board){

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto front = q.front();
                q.pop();
                int r = front.first;
                int c = front.second;
                for(int i=0;i<4;i++){
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if(nr>=0 && nc>=0 && nr<board.size() && nc<board[0].size() && !visited[nr][nc] && board[nr][nc]=='O'){
                        q.push({nr,nc});
                        visited[nr][nc]=true;
                    }
                }
            }
        }
        
}

void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;

        //first and last row 
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !visited[0][j]){
                q.push({0,j});
                visited[0][j]=true;
            }

            if(board[n-1][j]=='O' && !visited[n-1][j]){
                q.push({n-1,j});
                visited[n-1][j] = true;
            }
        }

        //first and last column
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !visited[i][0]){
                q.push({i,0});
                visited[i][0] = true;
            }
            if(board[i][m-1]=='O' && !visited[i][m-1]){
                q.push({i,m-1});
                visited[i][m-1] = true;
            }
        }

        bfs(q,visited,board);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
        
}

/*Same question of Replace O with X (just done using BFS approach)*/