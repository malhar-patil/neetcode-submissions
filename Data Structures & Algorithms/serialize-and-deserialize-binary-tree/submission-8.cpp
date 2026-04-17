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
    TreeNode* buildTree(string& s, int& index){
        if(index>= s.length() || s[index] == 'N'){
            return NULL;
        }
        int num = 0;
        string temp;
        index++;
        while(index< s.length() && s[index]!='*'){
            temp+=s[index];
            index++;
        }
        if(temp.length()>1){
            num = stoi(temp);
        }
        else if(temp.length()==1){
            num = stoi(temp);
        }
        TreeNode* root = new TreeNode(num);
        index++;
        root->left = buildTree(s, index);
        index++;
        root->right = buildTree(s, index);
        return root;
    }
    void dfs(TreeNode* root, string& s){
        if(root == NULL){
            s+='N';
            return;
        }
        int num = 0;
        s+=('*');
        s+=(to_string(root->val));
        s+=('*');
        dfs(root->left, s);
        dfs(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return buildTree(data,index);
    }
};
