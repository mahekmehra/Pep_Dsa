#include <iostream>
using namespace std;

class Node{
    
    public:
    
        int data;
        Node* left;
        Node* right;
        
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* buildTree(Node* root){
    
    cout<<"Enter data : "<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for left node "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right node "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void inorderPrint(Node* root){
    
    if(root==NULL){
        return;
    }
    
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    
    Node* root = NULL;
    root = buildTree(root);
    inorderPrint(root);
    return 0;
}