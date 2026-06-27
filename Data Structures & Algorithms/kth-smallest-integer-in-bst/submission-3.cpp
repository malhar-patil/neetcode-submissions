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
    void dfs(TreeNode* root,int& res, int& k){
        if(root == NULL){
            return;
        }

        dfs(root->left, res, k);
        k--;
        if(k==0){
            res =  root->val;
            return;
        }
        dfs(root->right, res, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        dfs(root, res, k);
        return res;
    }
};
