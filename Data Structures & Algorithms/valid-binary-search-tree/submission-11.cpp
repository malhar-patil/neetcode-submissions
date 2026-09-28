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
    bool dfs(TreeNode*& root, int minNum, int maxNum){
        if(root == NULL){
            return true;
        }

        if( !(root->val > minNum && root->val < maxNum) ){
            return false;
        }

        return dfs(root->left, minNum, min(maxNum, root->val)) && dfs(root->right, max(minNum, root->val), maxNum);
    }
    bool isValidBST(TreeNode* root) {
        int maxNum = INT_MAX;
        int minNum = INT_MIN;
        return dfs(root, minNum, maxNum);
    }
};
