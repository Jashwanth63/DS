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
    bool evaluateTree(TreeNode* root) {
        //if(root == nullptr) return false; // If no node, return false
        if(root->left==nullptr && root->right == nullptr) return root->val; // If at a leaf node return the value of the node
        // left, right, node
        bool left = evaluateTree(root->left); // get the value of the left leaf node
        bool right = evaluateTree(root->right); // Get the value of the right leaf node
        return root->val==3 ? (left&right): left|right; // At curr node, evaluate left and right (2->|, 3&)
    }
};