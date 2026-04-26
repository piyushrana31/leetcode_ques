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
    void inorder(TreeNode* root, vector<int> &sortedArray) {
        if(root == nullptr) return;

        inorder(root->left, sortedArray);
        sortedArray.push_back(root->val);
        inorder(root->right, sortedArray);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> sortedArray;

        inorder(root, sortedArray);

        int left = 0;
        int right = sortedArray.size()-1;

        while(left < right) {
            int sum = sortedArray[left] + sortedArray[right];
            if(sum > k) right--;
            else if(sum < k) left++;
            else return true;
        }

        return false;
    }
};