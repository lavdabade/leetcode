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
private:
    void inorderTraversal(TreeNode* root, vector<int> &inOrder) {
        if(!root) return;
        inorderTraversal(root->left, inOrder);
        inOrder.push_back(root->val);
        inorderTraversal(root->right, inOrder);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        inorderTraversal(root, inOrder);
        return inOrder;
    }
};