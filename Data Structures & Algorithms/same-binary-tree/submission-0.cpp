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
    bool ans=true;
    int getHeight(TreeNode* p, TreeNode* q){
        if(p==NULL && q!=NULL || p!=NULL && q==NULL){
            ans=false;
        }
        if(p==NULL || q==NULL){
            return 0;
        }

        getHeight(p->left,q->left);
        getHeight(p->right,q->right);
        if(p->val!=q->val){
            ans=false;
        }
        return 1;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int h = getHeight(p,q);
        return ans;
    }
};
