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
    void postorderTraversal(TreeNode* root, vector<int> &postOrder) {
        if(!root) return;
        postorderTraversal(root->left, postOrder);
        postorderTraversal(root->right, postOrder);
        postOrder.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        postorderTraversal(root, postOrder);
        return postOrder;
    }
};