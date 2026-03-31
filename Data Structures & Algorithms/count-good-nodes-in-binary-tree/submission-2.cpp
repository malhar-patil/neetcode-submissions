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
    void solve(TreeNode* root, int maxNum){
        if(root==NULL){
            return;
        }

        maxNum = max(maxNum,root->val);
        if(maxNum<=root->val){
            cout<<root->val<<endl;
            res++;
        }
        solve(root->left,maxNum);
        solve(root->right,maxNum);

    }
    int goodNodes(TreeNode* root) {
        solve(root,INT_MIN);
        return res;
    }
};
