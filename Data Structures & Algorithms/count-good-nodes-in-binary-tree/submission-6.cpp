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
    void dfs(TreeNode*& root, int maxNum, int& res){
        if(root == NULL){
            return;
        }
        if(root->val >= maxNum){
            res++;
        }
        maxNum = max(maxNum, root->val);
        dfs(root->left, maxNum, res);
        dfs(root->right, maxNum, res);
        return;
    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root, INT_MIN, res);
        return res;
    }
};
