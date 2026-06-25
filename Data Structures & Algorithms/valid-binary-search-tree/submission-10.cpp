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
    bool dfs(TreeNode* root, pair<int,int> minMax){
        if(root == NULL){
            return true;
        }

        if(!(root->val  > minMax.first && root->val < minMax.second)){
            return false;
        }

        bool left = dfs(root->left, {minMax.first, min(minMax.second, root->val)});
        bool right = dfs(root->right, {max(minMax.first, root->val),minMax.second});

        return left&&right;
    }
    bool isValidBST(TreeNode* root) {
        pair<int,int> minMax{INT_MIN, INT_MAX};
        return dfs(root, minMax);
    }
};
