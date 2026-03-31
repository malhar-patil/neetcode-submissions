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
    int solve(TreeNode* root, int & res){
        if(root==NULL){
            return 0;
        }
        
        int leftSum = solve(root->left, res);
        int rightSum = solve(root->right, res);

        int temp = max(max(root->val+leftSum,root->val+rightSum),max(root->val,root->val+leftSum+rightSum));
        res = max(res,temp);
        return max(max(root->val+leftSum,root->val+rightSum),root->val);
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int x = solve(root,res);
        return res;
    }
};
