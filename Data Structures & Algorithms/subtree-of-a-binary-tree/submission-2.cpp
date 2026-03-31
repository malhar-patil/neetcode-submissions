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
    bool ans=false;
    void checkTree(TreeNode* root, TreeNode* subRoot){
        if(root!=NULL && subRoot==NULL || root==NULL && subRoot!=NULL){
            ans=false;
            return;
        }
        if(root==NULL || subRoot==NULL){
            return;
        }

        checkTree(root->left, subRoot->left);
        checkTree(root->right, subRoot->right);
        if(root->val != subRoot->val){
            ans=false;
        }
    }
    void traverseRoot(TreeNode* root, TreeNode* subRoot){
        if(root==NULL){
            return;
        }

        if(root->val == subRoot->val){
            ans=true;
            checkTree(root,subRoot);
            if(ans==true){
                return;
            }
        }
        traverseRoot(root->left,subRoot);
        traverseRoot(root->right,subRoot);
    } 
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        traverseRoot(root,subRoot);
        return ans;
    }
};
