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
    void bfs(TreeNode*& root, vector<vector<int>>& res){
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        res.push_back({root->val});
        vector<int>level;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL){
                if(!q.empty()){
                    res.push_back(level);
                    level.clear();
                    q.push(NULL);
                }
                continue;
            }

            if(temp->left!=NULL){
                q.push(temp->left);
                level.push_back(temp->left->val);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
                level.push_back(temp->right->val);
            }
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        vector<vector<int>> res;
        bfs(root, res);
        return res;
    }
};
