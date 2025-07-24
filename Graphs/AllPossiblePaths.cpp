
class Solution {    //(dfs approach with backtracking)
public:

    void dfs(vector<vector<int>>& graph,vector<vector<int>> &res,vector<int> &temp,int u){

        temp.push_back(u);

        if(u==graph.size()-1){
            res.push_back({temp});
        }

        for(int &v : graph[u]){
            dfs(graph,res,temp,v);
        }

        temp.pop_back();
    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> res;
        vector<int> temp;
        dfs(graph,res,temp,0);
        return res;
        
    }
};

/*Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

 

Example 1:


Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.*/