/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int ans=INT_MIN;
    int solve(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int leftSum = max(0,solve(root->left)); // 10
        int rightSum = max(0,solve(root->right)); 
        int sum = max(root->val+leftSum,root->val+rightSum);
        // cout<<sum<<endl;
        ans = max(ans,root->val+rightSum+leftSum);
        cout<<ans<<endl;
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        int temp = solve(root);
        return max(root->val,ans);
    }
};
