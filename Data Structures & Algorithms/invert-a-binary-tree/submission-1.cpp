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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        queue<TreeNode*> queue1;
        queue1.push(root);

        while(!queue1.empty()){
            TreeNode* node = queue1.front();
            queue1.pop();
            swap(node->left, node->right);
            if(node->left) queue1.push(node->left);
            if(node->right) queue1.push(node->right);
        }
        return root;
    }
};
