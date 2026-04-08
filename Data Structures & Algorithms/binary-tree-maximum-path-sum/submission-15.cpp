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
    int dfs(TreeNode*& root, int& res){
        if(root == NULL){
            return 0;
        }

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        int tempMax = max(max(root->val, root->val+left+right), max(root->val+left, root->val+right));
        res = max(tempMax,res);
        return max(root->val, max(root->val+left, root->val+right));
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        int temp = dfs(root, res);
        return max(temp,res);
    }
};
