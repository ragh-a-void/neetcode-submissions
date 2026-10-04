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
    int maxDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        if(leftDepth == -1 or rightDepth == -1){
            return -1;
        }
        if(abs(leftDepth - rightDepth) > 1){
            return -1;
        }
        return max(leftDepth, rightDepth) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        int ans = maxDepth(root);
        return ans == -1 ? false : true;
    }
};
