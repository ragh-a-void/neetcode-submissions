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
    map<TreeNode*, int> currMax;
    void maxHelper(TreeNode* root, TreeNode* par){
        if(root == NULL){
            return;
        }
        if(par == NULL){
            currMax[root] = root->val;
        }else{
            currMax[root] = max(root->val, currMax[par]);
        }
        maxHelper(root->left, root);
        maxHelper(root->right, root);
    }
    int countHelper(TreeNode* root){
        if(!root){
            return 0;
        }
        int ans = 0;
        if(root->val >= currMax[root]){
            ans++;
        }
        ans += countHelper(root->left);
        ans += countHelper(root->right);
        return ans;
    }
public:
    int goodNodes(TreeNode* root) {
        maxHelper(root, NULL);
        return countHelper(root);
    }
};
