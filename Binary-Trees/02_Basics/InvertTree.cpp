//TC O(n) and SC O(h)
class Solution {
public:
void helper(TreeNode* root){
    if(root==NULL) return ;
    TreeNode* temp = root->left ;
    root->left = root->right ;
    root->right = temp ;
    helper(root->left );
    helper(root->right); 
}
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root ;
    }
};
