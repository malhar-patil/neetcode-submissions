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
    vector<vector<int>> solve(TreeNode* root){
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }

        vector<int> arr;
        arr.push_back(root->val);
        ans.push_back(arr);
        arr.clear();

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();

            if(temp==NULL){
                if(arr.size()>0){
                    ans.push_back(arr);
                    arr.clear();
                }
                if(!q.empty()){q.push(NULL);}
                continue;
            }

            if(temp->left!=NULL){
                q.push(temp->left);
                arr.push_back(temp->left->val);
            }

            if(temp->right!=NULL){
                q.push(temp->right);
                arr.push_back(temp->right->val);
            }
        }
        return ans;

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        return solve(root);
    }
};
