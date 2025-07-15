class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int maxi = INT_MIN;
            for(int i=0;i<size;i++){
                Node* temp = q.front();
                q.pop();
                maxi = max(maxi,temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(maxi);
        }
        return ans;
        
    }
};

/*Input :
        1
       / \
      2   3 

Output : 1 3
Explanation : 
There are two levels in the tree :
1. {1}, max = 1
2. {2, 3}, max = 3*/