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
    int isBalancedUtil(TreeNode* root) {
        if(!root) return 0;
        int isLeftBalanced = isBalancedUtil(root->left);
        if(isLeftBalanced == -1) return -1;
        int isRightBalanced = isBalancedUtil(root->right);
        if(isRightBalanced == -1) return -1;
        if(abs(isLeftBalanced - isRightBalanced) > 1) return -1;
        return 1 + max(isLeftBalanced, isRightBalanced);
    }

public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return isBalancedUtil(root) != -1;
    }
};