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
    int res = -1;
    void dfs(TreeNode* root, int k, int& cnt){
        if(root == NULL){
            return;
        }
        //inorder
        dfs(root->left, k, cnt);
        cnt++;
        if(k == cnt){
            res = root->val;
            return;
        }
        dfs(root->right, k, cnt);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        dfs(root, k, cnt);
        return res;
    }
};
