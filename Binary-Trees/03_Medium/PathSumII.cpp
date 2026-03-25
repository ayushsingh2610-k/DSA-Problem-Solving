// Time: O(n) | Space: O(h)
class Solution {
public:
    void sum(TreeNode* root,int targetsum ,int currsum,vector<int>a,vector<vector<int>>&ans){
       if(root==NULL)return ;
        a.push_back(root->val);
        currsum += root->val;
       if(root->left==NULL && root->right==NULL){
       if(targetsum==currsum){
        ans.push_back(a);
       };  
       return ;}
       sum(root->left,targetsum,currsum,a,ans);
       sum(root->right,targetsum,currsum,a,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>a;
        sum(root,targetSum,0,a,ans);
        return ans;
    }
};
