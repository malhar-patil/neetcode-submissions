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
    int ans=0;

    void traverse(TreeNode* root,int n){
        if(root==NULL){
            return;
        }
        if(root->val>=n){
            ans++;
        }
        n = max(n,root->val);
        traverse(root->left,n);
        traverse(root->right,n);
        
    }
    int goodNodes(TreeNode* root) {
        int n=INT_MIN;
        traverse(root,n);
        return ans;
    }
};
