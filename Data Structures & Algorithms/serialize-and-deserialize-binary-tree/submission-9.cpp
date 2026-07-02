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
    void dfsString(TreeNode* root, string& str){
        if(root==NULL){
            str.append("#N");
            return;
        }

        str +="#";
        str += to_string(root->val);

        dfsString(root->left, str);
        dfsString(root->right, str);
        return;
    }

    TreeNode* dfsBuild(int& index, string str){
        //cout<<index<<endl;
        if(index >= str.length()){
            return NULL;
        }

        int i = index+1;
        if(i < str.length() && str[i] == 'N'){
            TreeNode* root = NULL;
            index = i+1;
            return root;
        }
        string num = "";
        while(str[i] != '#' && i < str.length()){
            num += str[i++];
        }
        
        index = i;
        int number = stoi(num);
        TreeNode* root = new TreeNode(number);

        root->left = dfsBuild(index, str);
        root->right = dfsBuild(index, str);
        return root;
    }   
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        dfsString(root, res);
        cout<<res<<endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index = 0;
        return dfsBuild(index, data);
    }
};
