#include<bits/stdc++.h>
using namespace std ;
struct node{
    int data ;
    node*left ;
    node*right;
};
node*createNode(int val){
    node*NewNode= new node();
    NewNode->data=val;
    NewNode->left=nullptr;
    NewNode->right=nullptr ;
    return NewNode ;
}
node*insertNode(node*root,int val){
    if(root==nullptr) return  createNode(val);
    else{
        if(val<root->data){
            root->left=(insertNode(root->left,val));
        }
        else{
            root->right=insertNode(root->right,val);
        }
    }
    return root ;
}
node*searchNode(node*root,int val){
if(root==nullptr || root->data==val) return  root ;
else{
    if(val<root->data) {
        return searchNode(root->left,val);
    }
    else{
         return searchNode(root->right,val);
    }
}
}
node*findMin(node*root){
    if(root->left==nullptr || root==nullptr) return root;
     return findMin(root->left);
}
void inorder(node*root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
node*dltNode(node*root,int val){
    if(root==nullptr) return root ;
    else {
        if(val<root->data){
            root->left = dltNode(root->left,val);
        }
        else if(val>root->data){
            root->right=dltNode(root->right,val);
        }
        else{
            if(root->left==nullptr){
                node*temp=root->right;
                delete root;
                return temp ;
            }
            else if(root->right==nullptr){
                node*temp=root->left ;
                delete root ;
                return temp ;
            }
            node*temp=findMin(root->right);
            root->data = temp->data ;
            root->right = dltNode(root->right,temp->data);
        }
    }
}
int height(node*root){
    if(root==nullptr) return 0;
     return max(height(root->left),height(root->right))+1;
}
int main(){
    node*root=nullptr ;
    for(int i=0;i<10;i++){
  root=insertNode(root,i);
    }
inorder(root);
cout<<endl;
cout<<"height of the tree is : ";
cout<<height(root);

}

 
