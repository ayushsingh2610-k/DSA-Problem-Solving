//using dfs 
//TC O(n)
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
    cout<<root->val;
    display(root->left);
    display(root->right);
}

void nthlevel(Node* root,int level,int target){
    if(root==NULL)return ;
    if(level==target)cout<<root->val;
    nthlevel(root->left,level+1,target);
    nthlevel(root->right,level+1,target);

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
 nthlevel(a,1,2);
    return 0;
}
