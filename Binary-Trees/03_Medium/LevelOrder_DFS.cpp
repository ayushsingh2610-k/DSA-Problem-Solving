//using DFS (O(n^2) approach)
class Solution {
public:
int levels(TreeNode* root){
    if(root==NULL)return 0;
    return 1+max(levels(root->left),levels(root->right));
}
void kthlevel(TreeNode* root, vector<int>& v,int target,int s){
if(root==NULL )return ;
if(s==target)v.push_back(root->val);
kthlevel(root->left,v,target,s+1);
kthlevel(root->right,v,target,s+1);
}
void levelwise(TreeNode* root,vector<vector<int>>&ans){
    int n =levels(root);
    for(int i =1;i<=n;i++){
        vector<int>v;
        kthlevel(root,v,i,1);
        ans.push_back(v);
    }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>>ans;
    levelwise(root,ans);
    return ans;
    }
};
