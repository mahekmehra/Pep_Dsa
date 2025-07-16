
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // Your Code Here
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
            mp[line] = temp->data;
            
            if(temp->left) q.push({temp->left,line-1});
            if(temp->right) q.push({temp->right,line+1});
        }
        
        for(auto &it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};





/*Input: root[] = [1, 3, 2]

Output: [3 1 2]
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.*/