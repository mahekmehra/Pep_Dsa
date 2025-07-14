class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        if(root==NULL) return 0;
        
        int left = sumBT(root->left);
        int right = sumBT(root->right);
        
        return root->data + (left+right);
    }
};

//2nd approach
class Solution {
  public:
    int sumBT(Node* root) {
        // code here
        queue<Node*> q;
        if(root==NULL) return 0;
        q.push(root);
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* node = q.front();
                q.pop();
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
                count+=node->data;
            }
        }
        return count;
    }
};