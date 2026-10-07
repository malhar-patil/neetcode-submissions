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

class Codec {
public:

    TreeNode* buildTree(int& index, string& data){
        if(index > data.length()){
            return NULL;
        }

        int i = index;
        int j = index+1;
        while(j < data.length() && data[j] != '#'){
            j++;
        }

        string rootVal = data.substr(i+1, j - (i+1));
        if(rootVal == "N"){
            index = j+1;
            return NULL;
        }
        int val = stoi(rootVal);
        TreeNode* root = new TreeNode(val);
        index = j+1;
        root->left = buildTree(index, data);
        root->right = buildTree(index, data);
        return root;
    }
    void preorder(TreeNode* root, string& res){
        if(root == NULL){
            res.append("#N#");
            return;
        }

        //NLR
        string temp = to_string(root->val);
        res += ("#" + temp + "#");

        preorder(root->left, res);
        preorder(root->right, res);

        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res ="";
        preorder(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return buildTree(index, data);
    }
};
