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
    void dfs(TreeNode* root, int depth, unordered_set<int>& visited, vector<int>& res){
        if(root == NULL){
            return;
        }
        if(visited.find(depth)==visited.end()){
            visited.insert(depth);
            res.push_back(root->val);
        }
        dfs(root->right, depth+1, visited, res);
        dfs(root->left, depth+1, visited, res);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        unordered_set<int> visited;
        dfs(root, 0, visited, res);
        return res;
    }
};
