
int minValue(Node* root) {
        // Code here
        Node* temp = root;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp->data;
    }

//2nd approach (recursive)

int minValue(Node* root) {
        // Code here
        
        if(root->left==NULL) return root->data;
        return minValue(root->left);
    }