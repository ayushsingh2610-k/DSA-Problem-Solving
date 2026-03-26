// Time: O(n^2) | Space: O(h)

class Solution {
public:
     void find(TreeNode* root,int targetsum,long long currentsum,int &count){
        if(root==NULL)return ;
        currentsum+=root->val;
        if(targetsum==currentsum){
            count+=1;
        }
        find(root->left,targetsum,currentsum,count);
        find(root->right,targetsum,currentsum,count);
         }
     void solve(TreeNode* root,int targetsum,int &count){
      if(root==NULL)return  ;
      find(root,targetsum,0,count);
     solve(root->left,targetsum,count);
     solve(root->right,targetsum,count);
     }
    int pathSum(TreeNode* root, int targetSum) {
    int count=0;
    solve(root,targetSum,count);
    return count;
    }
};
