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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* node = new TreeNode(val);

        if(root == nullptr) return node;

        while(curr) {
            if(val > curr->val) {
                if(!curr->right) {
                    curr->right = node;
                    break;
                }
                else curr = curr->right;
            } else {
                if(!curr->left) {
                    curr->left = node;
                    break;
                }
                else curr = curr->left;
            }
        }

        return root;

    }
};