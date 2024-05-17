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
    TreeNode* dfs(TreeNode* root, int target){
        if(root == nullptr) return nullptr;
        if(root->left == nullptr && root->right == nullptr){
            TreeNode* temp = root; 
            if(temp->val == target){
                return nullptr;
            }
        }
        TreeNode* left = dfs(root->left, target);
        TreeNode* right = dfs(root->right, target);
        root->left = left;
        root->right = right;
        if(left == nullptr && right == nullptr && root->val == target){
            return nullptr;
        }
        return root;
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* head = dfs(root, target);
        return head;
    }
};