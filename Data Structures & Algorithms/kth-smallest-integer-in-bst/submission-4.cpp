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
    void dfs(TreeNode*& root, int k, priority_queue<int>& pq){
        if(root == NULL){
            return;
        }

        if(pq.size() < k){
            pq.push(root->val);
        }
        else if(pq.size() == k && root->val < pq.top()){
            pq.pop();
            pq.push(root->val);
        }

        dfs(root->right, k, pq);
        dfs(root->left, k, pq);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;
        dfs(root, k, pq);
        return pq.top();
    }
};
