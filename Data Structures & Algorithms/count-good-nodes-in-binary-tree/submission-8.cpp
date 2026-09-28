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
    void dfs(TreeNode*& root, int& res, int maxNode){
        if(root == NULL){
            return;
        }

        if(root->val >= maxNode){
            res++;
        }

        dfs(root->right, res, max(maxNode, root->val));
        dfs(root->left, res, max(maxNode, root->val));
        return;
    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        int maxNode = INT_MIN;
        dfs(root, res, maxNode);

        return res;
    }
};
