

void inorder(Node* root, int k,vector<int> &res){
        
        if(root==NULL) return;
        
        inorder(root->left,k,res);
        if(root->data<k){
            res.push_back(root->data);
        }
        inorder(root->right,k,res);
        
    }
    
    Node* construct(vector<int> res,int low,int high){
        
        if(low>high) return NULL;
        
        int mid = low + (high-low)/2;
        
        Node* root = new Node(res[mid]);
        root->left = construct(res,low,mid-1);
        root->right = construct(res,mid+1,high);
        
        return root;
    }
    
    
    Node* deleteNode(Node* root, int k) {
        // Your code here
        vector<int> res;
        inorder(root,k,res);
        int low = 0;
        int high = res.size()-1;
        return construct(res,low,high);
        
        
    }

/*Given a BST and a value k, the task is to delete the nodes having values greater than or equal to k.

Example 1:

Input:
    4   
   / \  
  1   9 
k = 2 
Output:
1*/