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
    bool isValid(TreeNode* root, TreeNode* subRoot){
        if((root==NULL && subRoot!=NULL) || (root!=NULL && subRoot==NULL)){
            return false;
        }
        if(root==NULL && subRoot==NULL){
            return true;
        }
        if(subRoot->val!=root->val){
            return false;
        }
        bool ans = (isValid(root->left,subRoot->left) && isValid(root->right,subRoot->right));
        return ans;
    }
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(root==NULL){
            return false;;
        }
        if(root->val == subRoot->val){
            if(isValid(root,subRoot)){
                return true;
            }
        }
        bool ans = (solve(root->left,subRoot) || solve(root->right,subRoot));
        return ans;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL){return true;}
        return solve(root,subRoot);
    }
};
