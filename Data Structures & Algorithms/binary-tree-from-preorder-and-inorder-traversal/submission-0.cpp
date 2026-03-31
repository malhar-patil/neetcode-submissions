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
    int pre_index=0;
    unordered_map<int,int> m;
    TreeNode* construct(vector<int>& preorder,int l,int r){
        if(l>r){return NULL;}
        int nodeNum=preorder[pre_index++];
        TreeNode* root = new TreeNode(nodeNum);
        int mid = m[nodeNum];
        root->left = construct(preorder,l,mid-1);
        root->right = construct(preorder,mid+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()!=inorder.size()){return NULL;}
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        return construct(preorder,0,preorder.size()-1);
    }
};
