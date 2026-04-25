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
    TreeNode* bstFromPreorder(vector<int>& preorder, int start, int end) {
        if(start > end) return nullptr;

        TreeNode* root = new TreeNode(preorder[start]);
        int split = start+1;
        while(split <= end && root->val > preorder[split]) {
            split++;
        }

        root->left = bstFromPreorder(preorder, start+1, split-1);

        root->right = bstFromPreorder(preorder, split, end);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = bstFromPreorder(preorder, 0, preorder.size()-1);

        return root;
    }
};