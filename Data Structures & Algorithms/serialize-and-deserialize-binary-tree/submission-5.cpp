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
    void serializeTree(TreeNode* root, string& s){
        if(root==NULL){
            s=s+'N';
            return;
        }
        s.append("*");
        s.append(to_string(root->val));
        s.append("*");
        serializeTree(root->left,s);
        serializeTree(root->right,s);
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serializeTree(root,res);
        return res;
    }
    TreeNode* solve(string s,int& index){
        if(index>=s.length()){
            return NULL;
        }
        if(s[index] == 'N'){
            return NULL;
        }

        string value; index++;

        while(s[index]!='*'){
            value.push_back(s[index]);
            index++;
        }   

        TreeNode* root = new TreeNode(stoi(value));
        root->left = solve(s,++index);
        root->right = solve(s,++index);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()<=0){return NULL;}
        int index=0;
        return solve(data,index);
    }
};
