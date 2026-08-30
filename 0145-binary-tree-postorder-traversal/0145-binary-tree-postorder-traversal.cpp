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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        while(root) {
            TreeNode* right = root->right;
            if(right) {
                while(right->left && right->left != root) {
                    right = right->left;
                }
                if(right->left) {
                    right->left = nullptr;
                    root = root->left;
                }
                else {
                    right->left = root;
                    postOrder.push_back(root->val);
                    root = root->right;
                }
            }
            else {
                postOrder.push_back(root->val);
                root = root->left;
            }
        }
        reverse(postOrder.begin(), postOrder.end());
        return postOrder;
    }
};

class Solution_Iterative {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if(!root) return postOrder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            postOrder.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right) st.push(node->right);
        }
        reverse(postOrder.begin(), postOrder.end());
        return postOrder;
    }
};

class Solution_Recursion {
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