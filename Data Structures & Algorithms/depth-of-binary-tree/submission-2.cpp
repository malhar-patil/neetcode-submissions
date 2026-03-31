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
    int res = 0;
    void solve(TreeNode* root,int temp){
        if(root==NULL){
            return;
        }
        temp++;
        res = max(temp,res);
        solve(root->left,temp);
        solve(root->right,temp);
    }
    int maxDepth(TreeNode* root) {
        solve(root,0);
        return res;
    }
};
