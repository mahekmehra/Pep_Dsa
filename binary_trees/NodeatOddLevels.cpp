class Solution {
  public:
    vector<int> nodesAtOddLevels(Node *root) {
        // code here
        queue<Node*> q;
        vector<int> ans;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node *temp = q.front();
                q.pop();
                if(flag){
                    ans.push_back(temp->data);
                }
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            flag=!flag;
        }
        return ans;
    }
};

/*Input: root = [1, 2, 3, 4, 5, N, 6, N, N, 7, 8, 9]
          1
       /     \
      2       3
    /   \       \
   4     5       6
        /  \     /
       7    8   9
Output:  [1, 4, 5, 6]
Explanation: The odd levels are 1 and 3 and thier node are 1 and 4 5 6 respectively. */