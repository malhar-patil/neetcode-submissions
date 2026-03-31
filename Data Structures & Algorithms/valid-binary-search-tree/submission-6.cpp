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
    bool solve(TreeNode* root, int left, int right){
        if(root==NULL){
            return true;
        }

        if(!(root->val>left && root->val<right)){
            return false;
        }

        bool res = (solve(root->left,left,root->val) && solve(root->right,root->val,right));
        return res;
    }
    bool isValidBST(TreeNode* root) {
        return solve(root,INT_MIN,INT_MAX);

    }
};
