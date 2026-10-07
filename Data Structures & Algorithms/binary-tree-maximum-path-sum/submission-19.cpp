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
    int dfs(TreeNode* root, int& res){
        if(root == NULL){
            return 0;
        }

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);

        int temp1 = root->val + left + right;
        int temp2 = root->val + left;
        int temp3 = root->val + right;
        int temp4 = root->val;

        int tempRes = max(max(temp1, temp2), max(temp3, temp4));
        res = max(res, tempRes);

        return max(max(temp2, temp3), temp4);
        
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;

        int temp = dfs(root, res);
        return res;
    }
};
