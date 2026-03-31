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
    void inorderTraversal(TreeNode* root, vector<TreeNode*> &arr){
        if(root==NULL){
            return;
        }
        inorderTraversal(root->left,arr);
        arr.push_back(root);
        inorderTraversal(root->right,arr);
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<TreeNode*> arr;
        inorderTraversal(root,arr);

        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]->val >= arr[i+1]->val){
                return false;
            }
        }
        return true;
    }
};
