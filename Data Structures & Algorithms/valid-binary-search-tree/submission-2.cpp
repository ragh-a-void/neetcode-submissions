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
    bool bstHelper(TreeNode* root, int minVal, int maxVal){
        if(!root){
            return true;
        }
        if(root->val <= minVal or root->val >= maxVal){
            return false;
        }
        return bstHelper(root->left, minVal, root->val) and bstHelper(root->right, root->val, maxVal);
    }
public:
    bool isValidBST(TreeNode* root) {
        return bstHelper(root, INT_MIN, INT_MAX);
    }
};
