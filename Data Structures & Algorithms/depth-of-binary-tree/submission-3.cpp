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
    int levelOrderTraversal(TreeNode* root){
        int res= 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        res++;

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp==NULL && !q.empty()){
                res++;
                q.push(NULL);
                continue;
            }
            if(temp==NULL){break;}
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        return res;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return levelOrderTraversal(root);
    }
};
