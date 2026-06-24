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
TreeNode* minInBST(TreeNode* root){
    while(root->left!=NULL){
        root = root->left;
    }

    return root;
}

TreeNode* maxInBST(TreeNode* root){
    while(root->right!= NULL){
        root=root->right;
    }
    return root;
}
pair<TreeNode*,TreeNode*> inorderPreSuc (TreeNode* root, int val){
    TreeNode* pre = NULL;
    TreeNode* suc = NULL;

    while(root!=NULL){
        if(root->val < val){
            pre = root;
            root = root->right;
        }
        else if(root->val > val){
            suc = root;
            root = root->left;
        }
        else{
            if(root->left){
                pre = maxInBST(root->left);
            }
            if(root->right){
                suc = minInBST(root->right);
            }
            break;
        }
    }

    return {pre, suc};
}
    TreeNode* deleteN(TreeNode* root, int key){
        if(root == NULL){
            return root;
        }

        if(root->val == key){
            //0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }

            //1 child
            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            //2child

            if(root->right!=NULL && root->left!=NULL){
                pair<TreeNode*,TreeNode*> p = inorderPreSuc(root, key);
                root->val = p.second->val;
                root->right = deleteN(root->right, p.second->val);
                return root;
            }

        }
        else if(root->val < key){
            root->right = deleteN(root->right, key);
            return root;
        }
        else{
            root->left = deleteN(root->left, key);
            return root;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return deleteN(root, key);
    }
};