//BFS level order (O(n))
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode* >q;
    if(root==NULL)return {};
    q.push(root);
    vector<vector<int>>ans;
    while(q.size()!=0){
        int s=q.size();
        vector<int>v;
        for(int i =0;i<s;i++){
        TreeNode* a=q.front();
        q.pop();
         if(a!=NULL)v.push_back(a->val);
         if(a->left!=NULL)q.push(a->left);
         if(a->right!=NULL)q.push(a->right);
        }
        ans.push_back(v);
    }
    return ans;
}};
