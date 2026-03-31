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
    bool res = true;
    void solve(TreeNode* p, TreeNode*q){
        if((p==NULL && q!=NULL) || (p!=NULL && q==NULL)){
            res = false;
            return;
        }
        if(p==NULL && q==NULL){
            return;
        }
        if(p->val!=q->val){
            res=false;
            return;
        }
        solve(p->left,q->left);
        solve(p->right,q->right);
        return;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        solve(p,q);
        return res;
    }
};
