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
    int currCount = 0, ans = INT_MIN;
    void countHelper(TreeNode* root, int k){
        if(!root){
            return;
        }
        countHelper(root->left, k);
        currCount++;
        if(currCount == k){
            ans = root->val;
        }
        countHelper(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        countHelper(root, k);
        return ans;
    }
};
