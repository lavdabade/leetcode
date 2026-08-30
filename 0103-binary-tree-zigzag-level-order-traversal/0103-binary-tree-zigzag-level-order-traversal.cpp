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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagLevelOrderTraversal;
        if(!root) return zigzagLevelOrderTraversal;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()) {
            int qSize = q.size();
            vector<int> currentLevelNode(qSize);
            int processNodeCnt = 0;
            while(qSize--) {
                TreeNode* node = q.front();
                q.pop();
                currentLevelNode[leftToRight ? processNodeCnt : qSize] = node->val;
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
                processNodeCnt++;
            }
            leftToRight = !leftToRight;
            zigzagLevelOrderTraversal.push_back(currentLevelNode);
        }
        return zigzagLevelOrderTraversal;
    }
};