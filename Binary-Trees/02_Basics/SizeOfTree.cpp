// Problem: Size of Binary Tree
// Approach: Recursion
// Time: O(n) | Space: O(h)

#include <iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int val;
    Node* left ;
    Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
void display(Node* root){
    if(root==NULL)return ;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int size(Node* root){
    if(root==NULL)return 0;
    int s=1+(size(root->right)+size(root->left));
    return s;
}
int main() {
   Node* a= new Node(5);
   Node* b= new Node(4);
   Node* c= new Node(3);
   Node* d= new Node(6);
   Node* e=new Node(2);
  a->left= b;
  a->right=c;
  b->left=d;
  b->right=e;
display(a);
cout<<"\n";
cout<<size(a);
    return 0;
}
