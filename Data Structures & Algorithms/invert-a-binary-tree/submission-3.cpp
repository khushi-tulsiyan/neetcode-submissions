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
    // TreeNode* invertTree(TreeNode* root) {
    //     if(!root) return nullptr;

    //     swap(root->left, root->right);

    //     invertTree(root->left);
    //     invertTree(root->right);

    //     return root;
    // }


    TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) return nullptr;

    abc(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);

    return root;
    }

    void abc(TreeNode* &node1, TreeNode* &node2){
        TreeNode* node3;
        node3 = node1;
        node1 = node2;
        node2 = node3;

        
    }

};






