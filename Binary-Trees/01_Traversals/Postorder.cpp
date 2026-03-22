//using dfs left ->right ->root
//SC O(n) and TC O(h)

class Solution {
public:
void postorder(TreeNode* root,vector<int>& ans){
    if(root==NULL) return ;
    postorder(root->left ,ans);
    postorder(root ->right,ans);
    ans.push_back(root->val);
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans ;
        postorder(root,ans);
        return ans ;
        
    }
};
