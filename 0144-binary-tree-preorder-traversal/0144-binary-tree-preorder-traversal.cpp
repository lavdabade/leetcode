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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        while(root) {
            TreeNode* left = root->left;
            if(left) {
                while(left->right != nullptr && left->right != root) {
                    left = left->right;
                }
                if(left->right == nullptr) {
                    left->right = root;
                    preOrder.push_back(root->val);
                    root = root->left;
                }
                else {
                    left->right = nullptr;
                    root = root->right;
                }
            }
            else {
                preOrder.push_back(root->val);
                root = root->right;
            }
        }
        return preOrder;
    }
};

class Solution_Iterative {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(!root) return preOrder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            preOrder.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return preOrder;
    }
};

class Solution_Recursion {
private:
    void preorderTraversalUtil(TreeNode* root, vector<int> &preOrder) {
        if(!root) return;
        preOrder.push_back(root->val);
        preorderTraversalUtil(root->left, preOrder);
        preorderTraversalUtil(root->right, preOrder);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        preorderTraversalUtil(root, preOrder);
        return preOrder;
    }
};