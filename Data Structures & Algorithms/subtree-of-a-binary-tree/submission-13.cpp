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
    bool check (TreeNode*& p, TreeNode*& q){
        if(!p && !q){
            return true;
        }

        if((!p && q) || (p && !q)){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        bool left = check (p->left, q->left);
        bool right = check (p->right, q->right);

        return left && right;
    }
    void dfs(TreeNode*& p, TreeNode*& q, bool& ans){
        if(!p || !q){
            return;
        }
        if(p->val == q->val && check(p, q)){
            ans = true;
            return;
        }

        dfs(p->left, q, ans);
        dfs(p->right, q, ans);

        return;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool ans = false;
        dfs(root, subRoot, ans);
        return ans;
    }
};
