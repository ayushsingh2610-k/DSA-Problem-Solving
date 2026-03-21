// Problem: Diameter of Binary Tree
// Approach: DFS (height + diameter in one pass)
// Time: O(n) | Space: O(h)
class Solution {
public:
int helper(TreeNode* root , int &md ){
if(root==NULL) return 0 ;
int left=helper(root->left,md);
int right=helper(root->right,md);
md=max(md,left+right);
return 1+max(left,right);
}



    int diameterOfBinaryTree(TreeNode* root) {
        int md=0;
        helper(root,md);
        return md ;
        
    }
};
