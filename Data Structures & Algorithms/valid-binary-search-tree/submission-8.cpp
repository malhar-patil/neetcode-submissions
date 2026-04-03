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
    bool dfs(TreeNode*& root, pair<long long, long long> interval){
        if(root == NULL){
            return true;
        }
        if(!(root->val > interval.first && root->val <interval.second)){
            return false;
        }
        bool left = dfs(root->left, {interval.first, min((long long)root->val, interval.second)});
        bool right = dfs(root->right, {max(interval.first, (long long)root->val), interval.second});
        if(left && right){
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        // if((root->val ==INT_MAX || root->val == INT_MIN) && (root->left == NULL && root->right == NULL)){
        //     return true;
        // }
        pair<long long, long long> interval {LLONG_MIN, LLONG_MAX};
        return dfs(root, interval);
    }
};
