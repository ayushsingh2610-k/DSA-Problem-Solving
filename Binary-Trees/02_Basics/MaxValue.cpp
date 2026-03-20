// Problem: Maximum Value in Binary Tree
// Approach: Recursion
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
int findmax(Node* root){
    if(root==NULL)return INT_MIN;
    int lmax=findmax(root->left);
    int rmax=findmax(root->right);
    return max(root->val,max(lmax,rmax));
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
cout<<findmax(a);
    return 0;
}
