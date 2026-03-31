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
    void inorderTraversal(TreeNode* root, int &n, bool &ans){
        if(root==NULL){
            return;
        }

        inorderTraversal(root->left,n,ans);
        if(n>=root->val){
            ans = false;
            return;
        }
        n=root->val;
        inorderTraversal(root->right,n,ans);
        return;
    }
    bool isValidBST(TreeNode* root) {
        int n = INT_MIN;
        bool ans = true;
        inorderTraversal(root,n,ans);
        return ans;
    }
};
