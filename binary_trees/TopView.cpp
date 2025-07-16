    
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            Node* temp = curr.first;
            int line = curr.second;
            if(mp.find(line)==mp.end()){
                mp[line] = temp->data;
            }
            
            if(temp->left) q.push({temp->left,line-1});
            if(temp->right) q.push({temp->right,line+1});
        }
        
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};

/*Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \   
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explanation: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.*/