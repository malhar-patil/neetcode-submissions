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
    int dfs(TreeNode* root, bool& res){
        if(root == NULL){
            return 0;
        }

        //right
        int right = dfs(root->right, res) + 1;

        //left 
        int left = dfs(root->left, res) + 1;

        if(abs(left-right) > 1){
            res = false;
        }
        return max(left, right);
    }


    bool isBalanced(TreeNode* root) {
        bool res = true;
        int val = dfs(root, res);
        return res;
    }
};
