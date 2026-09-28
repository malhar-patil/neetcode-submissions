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
    void dfs(TreeNode*& root, int level, vector<int>& res, unordered_set<int>& s){
        if(root == NULL){
            return;
        }

        if(!s.contains(level)){
            s.insert(level);
            res.push_back(root->val);
        }

        dfs(root->right, level+1, res, s);
        dfs(root->left, level+1, res, s);

        return;

        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        unordered_set<int>s;
        dfs(root, 1, res, s);
        return res;
    }
};
