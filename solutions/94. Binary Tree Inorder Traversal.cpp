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
    
    void printInOrder(TreeNode* &r, vector<int> &v) {
        if(r==nullptr)   return;
        printInOrder(r->left, v);
        //cout << r->val;
        v.push_back(r->val);
        printInOrder(r->right, v);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        
        printInOrder(root, v);
        return v;
    }
};
