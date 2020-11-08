/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isMirror(TreeNode* l, TreeNode* r) {
        if(!l&&!r)  return true;
        if(!l || !r)    return false;
        
        return r->val==l->val && isMirror(l->left, r->right) && isMirror(r->left, l->right);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)   return true;
        if(!root->left && !root->right) return true;
        
        return isMirror(root->left, root->right);
    }
};