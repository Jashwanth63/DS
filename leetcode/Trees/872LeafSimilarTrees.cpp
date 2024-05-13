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
    void traverse(TreeNode* root, string &leaves){
        if(root == nullptr) return;
        //Check if there are nodes to left and right, if no nodes it is a leaf node
        if(root->right == nullptr && root->left == nullptr) leaves+=root->val+'0';
        traverse(root->left, leaves);
        traverse(root->right, leaves);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string leftString;
        string rightString;
        traverse(root1, leftString);
        traverse(root2, rightString);
        if(leftString == rightString) return true;
        return false;
    }
};