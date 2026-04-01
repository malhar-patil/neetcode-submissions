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
    int res = 0;
    int solve(TreeNode*& root){
        if(root == NULL){
            return 0;
        }

        int left = solve(root->left);
        int right = solve(root->right);
        res = max(res, left+right+1);
        return max(left+1, right+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int temp = solve(root);
        return res-1;
    }
};
