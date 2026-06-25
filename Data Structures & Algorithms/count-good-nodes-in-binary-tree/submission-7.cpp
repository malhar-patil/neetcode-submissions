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
    int count(TreeNode* root, int minNum){
        if(root == NULL){
            return 0;
        }

        int left = count(root->left, max(minNum, root->val));
        int right = count(root->right, max(minNum, root->val));

        if(root->val >= minNum){
            return 1 + left + right;
        }
        return left+right;
    }
    int goodNodes(TreeNode* root) {
        return count(root, INT_MIN);
    }
};
