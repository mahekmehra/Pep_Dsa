
TreeNode* min(TreeNode* root){

        TreeNode* temp = root;
        while(temp->left!=NULL){
            temp=temp->left;
        }

        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        if(root==NULL) return root;

        if(root->val==key){

            if(!root->left && !root->right){
                delete root;
                return NULL;
            }
            if(root->left && !root->right){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            if(!root->left && root->right){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(root->left && root->right){
                int mini = min(root->right)->val;
                root->val = mini;
                root->right=deleteNode(root->right,mini);
                return root;
            }
        }else if(root->val>key){
            root->left = deleteNode(root->left,key);

        }else{
            root->right = deleteNode(root->right,key);
        }
        
        return root;
    }


    //Another approach

    class Solution {
public:

    void inorder(TreeNode* root,vector<int> &res){

        if(root==NULL) return;

        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }

    TreeNode* build(TreeNode* root,int val){

        if(root==NULL){
            TreeNode* nt = new TreeNode(val);
            return nt;
        }

        if(root->val>val){
            root->left = build(root->left,val);
        }else{
            root->right = build(root->right,val);
        }

        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {

        vector<int> res;
        if(root==NULL) return root;
        inorder(root,res);
        auto it = find(res.begin(), res.end(), key);
        if(it != res.end()) {
            res.erase(it);
        } else {
            return root;  // key not found, return original tree
        }

        TreeNode* newroot=NULL;
        for(auto &i:res){
            newroot = build(newroot,i);
        }

        return newroot;
        
    }
};

//for two child case
//1> replace the root data with maximum value of left subtree
//OR replace the root data with minimum value of right subtree
// then delete that min/max value from the tree