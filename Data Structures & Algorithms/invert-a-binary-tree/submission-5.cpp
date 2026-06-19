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
    TreeNode* dfs(TreeNode* root){

        //preorder

        if(root == NULL){
            return NULL;
        }

        TreeNode* temp = root->right;
        root->right = dfs(root->left);
        root->left = dfs(temp);

        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        //preorder
        return dfs(root);
    }
};
