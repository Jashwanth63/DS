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
    
    int dfs(TreeNode* root, int &excess){
        if(root == nullptr) return 0;

        int leftExcess = dfs(root->left, excess);
        int rightExcess = dfs(root->right, excess);
        excess += abs(leftExcess) + abs(rightExcess);
        return leftExcess + rightExcess + root->val - 1;


    }
    
    int distributeCoins(TreeNode* root) {
       int excess = 0;
       dfs(root, excess);
       return excess;
    }
};