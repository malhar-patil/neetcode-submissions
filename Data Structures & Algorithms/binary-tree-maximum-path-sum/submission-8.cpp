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
        int leftSum = solve(root->left); // 10
        int rightSum = solve(root->right); 
        int sum = max(0,max(root->val+leftSum,root->val+rightSum));
        ans = max(ans,root->val+rightSum+leftSum);
        return sum;
    }
    int maxPathSum(TreeNode* root) {
        int temp = solve(root);
        return max(root->val,ans);
    }
};
