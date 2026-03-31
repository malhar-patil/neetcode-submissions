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
    void solve(TreeNode*& root, int maxNum,int& res){
        if(root==NULL){
            return;
        }

        maxNum = max(maxNum,root->val);
        if(maxNum<=root->val){
            cout<<root->val<<endl;
            res++;
        }
        solve(root->left,maxNum,res);
        solve(root->right,maxNum,res);

    }
    int goodNodes(TreeNode* root) {
        int res = 0;
        solve(root,INT_MIN, res);
        return res;
    }
};
