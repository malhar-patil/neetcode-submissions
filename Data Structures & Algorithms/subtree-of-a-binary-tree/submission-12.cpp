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
    bool dfs(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL ){
            return true;
        }

        if((p == NULL && q!=NULL) || (p!=NULL && q==NULL)){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        return (dfs(p->left, q->left) && dfs(p->right, q->right));
    }
    bool traverse(TreeNode* p, TreeNode* q){
        if(p == NULL){
            return false;
        }

        if(p->val == q->val && dfs(p, q)){
            return true;
        }

        return (traverse(p->left, q) || traverse(p->right, q));
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return traverse(root, subRoot);
    }
};
