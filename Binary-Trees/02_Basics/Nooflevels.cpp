// Problem: Height of Binary Tree
// Approach: Recursion (DFS)
// Time: O(n) | Space: O(h)
#include <iostream>
#include<vector>
#include<climits>
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
int maxlevels(Node* root){
    if(root==NULL)return 0;
    return 1+max(maxlevels(root->left),maxlevels(root->right));
}
void display(Node* root){
    if(root==NULL)return ;
    cout<<root->val;
    display(root->left);
    display(root->right);
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
cout<<maxlevels(a);
    return 0;
}
