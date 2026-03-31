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
    string s;
    int index=0;
    void traverseTree(TreeNode* root){
        if(root==NULL){
            s+='N';
            return;
        }
        
        s+= '*' + to_string(root->val) + '*';
        traverseTree(root->left);
        traverseTree(root->right);
        return;
    }

    TreeNode* constructTree(){
        if(index>=s.length()){return NULL;}
        if(s[index]=='N'){index++;return NULL;}
        
        string num;
        if(s[index]=='*'){
            index++;
        }
        while(index<s.length() && s[index]!='*'){
            num+=s[index];index++;
        }
        TreeNode* temp = new TreeNode(stoi(num));
        index++;
        temp->left = constructTree();
        temp->right = constructTree();
        return temp;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        traverseTree(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0){
            return NULL;
        }
        s = data;
        return constructTree();
    }
};
