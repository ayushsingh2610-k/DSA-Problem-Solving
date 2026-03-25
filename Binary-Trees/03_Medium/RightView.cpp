
// Time: O(n^2) | Space: O(h)
class Solution {
public:
 int levels(TreeNode* root){
    if(root==NULL)return 0;
    return 1+max(levels(root->left),levels(root->right));
 }
 void find(TreeNode* root,vector<int>&ans,int curr,int reqlevel){
   if(root==NULL)return ;
   if(curr==reqlevel){
    ans[curr]=(root->val);
    return ;
   }
   find(root->left,ans,curr+1,reqlevel);
   find(root->right,ans,curr+1,reqlevel);
 }
    vector<int> rightSideView(TreeNode* root) {
        int n=levels(root);
        vector<int>ans(n);
        if(root!=NULL)ans[0]=(root->val);
        for(int i=1;i<n;i++){
          find(root,ans,0,i);
        }
       return  ans;
    }
};
