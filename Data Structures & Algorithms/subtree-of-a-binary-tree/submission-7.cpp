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
    bool res = false;
    void isValid(TreeNode* root, TreeNode* subRoot){
        if((root==NULL && subRoot!=NULL) || (root!=NULL && subRoot==NULL)){
            res = false;
            return;
        }
        if(root==NULL && subRoot==NULL){
            return;
        }

        if(subRoot->val!=root->val){
            res = false;
            return;
        }
        isValid(root->left,subRoot->left);
        isValid(root->right,subRoot->right);
        return;
    }
    void solve(TreeNode* root, TreeNode* subRoot){
        if(root==NULL){
            return;
        }
        if(root->val == subRoot->val){
            res = true;
            isValid(root,subRoot);
            if(res){return;}
        }
        solve(root->left,subRoot);
        solve(root->right,subRoot);
        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL){return true;}
        solve(root,subRoot);
        return res;
    }
};
