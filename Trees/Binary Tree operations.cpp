#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
static int idx=-1;
Node *buildTree(vector<int>preorder){
    idx++;
    if(preorder[idx]==-1) return NULL;
    Node *root=new Node(preorder[idx]);
    root->left=buildTree(preorder);
    root->right=buildTree(preorder);
    return root;
}

void preOrder(Node *root){  //root,left,right
   if(root==NULL) return;
   cout<<root->data;
   preOrder(root->left);
   preOrder(root->right);
}
void inOrder(Node *root){  //left,root,right
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->data;
    inOrder(root->right);
}
void postOrder(Node *root){
    if(root==NULL) return;  //left,right,root
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data;
}

void levelOrder(Node *root){ //level wise
    queue<Node *>q;
    q.push(root);
    while(!q.empty()){
        Node *curr=q.front();
        q.pop();
        cout<<curr->data;
        if(curr->left!=0) q.push(curr->left);
        if(curr->right!=0) q.push(curr->right);
    }
}

int height(Node *root){
    if(root==NULL) return 0;
    int left_tree=height(root->left);
    int right_tree=height(root->right);
    return max(left_tree,right_tree)+1;
}
int sum(Node *root){
    if(root==NULL) return 0;
    int left_tree=sum(root->left);
    int right_tree=sum(root->right);
    return left_tree+right_tree+root->data;
}
int count(Node *root){
    if(root==NULL) return 0;
    int left_tree=count(root->left);
    int right_tree=count(root->right);
    return left_tree+right_tree+1;
}
int main(){
    vector<int>preorder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node *root=buildTree(preorder);
    preOrder(root);
    inOrder(root);
    postOrder(root);
    levelOrder(root);
    cout<<endl<<"Height of Tree is: "<<height(root)<<endl;
    cout<<"Sum of Nodes is: "<<sum(root)<<endl;
    cout<<"Total no. of nodes is: "<<count(root);
    return 0;
}