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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }

        if((p->val>=root->val && q->val<=root->val) || (p->val<=root->val && q->val>=root->val)){
            return root;
        }
        else if(root->val<p->val && root->val<q->val){
            root = root->right;
            return lowestCommonAncestor(root,p,q);
        }
        else{
            root=root->left;
            return lowestCommonAncestor(root,p,q);
        }
        return root;
    }
};
