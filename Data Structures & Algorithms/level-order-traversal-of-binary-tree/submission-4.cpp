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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            return {};
        }
        queue<TreeNode*> q;
        vector<vector<int>>res;

        q.push(root);
        q.push(NULL);
        vector<int> level;
        res.push_back({root->val});

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                if(level.size()>0)
                res.push_back(level);
                level.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }

            if(temp->left != NULL){
                q.push(temp->left);
                level.push_back(temp->left->val);
            }

            if(temp->right != NULL){
                q.push(temp->right);
                level.push_back(temp->right->val);
            }
        } 

        return res;
    }
};
