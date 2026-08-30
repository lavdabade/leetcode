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
    void rightSideView(TreeNode* root, int level, vector<int> &rightView) {
        if(!root) return;
        if(level == rightView.size()) {
            rightView.push_back(root->val);
        }
        rightSideView(root->right, level+1, rightView);
        rightSideView(root->left, level+1, rightView);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightView;
        rightSideView(root, 0, rightView);
        return rightView;
    }
};