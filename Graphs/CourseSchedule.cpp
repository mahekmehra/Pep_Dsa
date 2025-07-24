class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        queue<int> q;
        vector<int> indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto p : adj[i]){
                indegree[p]++;
            }
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> res;
        while(!q.empty()){
            int m = q.front();
            res.push_back(m);
            q.pop();
            for(int &k : adj[m]){
                indegree[k]--;
                if(indegree[k]==0){
                    q.push(k);
                }
            }
        }

        return (res.size()==numCourses);
        
    }
};

//approach 2 (using dfs cycle detection)

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

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses,false);
        vector<bool> recurse(numCourses,false);
        
        for(int i=0;i<numCourses;i++){
            if(!visited[i] && dfs(visited,recurse,adj,i)){
                return false;
            }
        }
        return true;
        
}


/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.*/