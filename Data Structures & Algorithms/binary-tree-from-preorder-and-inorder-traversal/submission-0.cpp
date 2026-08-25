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
    int preIdx = 0;
    TreeNode* treeHelper(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderIdx){
        if(inStart > inEnd){
            return NULL;
        }
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int inIdx = inorderIdx[rootVal];
        root->left = treeHelper(preorder, inorder, inStart, inIdx-1, inorderIdx);
        root->right = treeHelper(preorder, inorder, inIdx+1, inEnd, inorderIdx);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIdx;
        int n = inorder.size();
        for(int i = 0; i < n; i++){
            inorderIdx[inorder[i]] = i;
        }
        return treeHelper(preorder, inorder, 0, n-1, inorderIdx);
    }
};
