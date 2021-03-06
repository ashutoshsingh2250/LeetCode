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
    //[1,2,3,null,5,null,4,6,7,null,8,null,9,10,null,null,11,12,13,14,null,null,null,15]
    int prev=-1, curr=-1;
    vector<int> v;
    void DFS(TreeNode* root) {
        if(root==nullptr)   return;
        if(root) curr++;
        
        if(curr>prev) {
            prev=curr;
            cout << root->val << " ";
            v.push_back(root->val);
        }
            
        DFS(root->right);
        DFS(root->left);
        curr--;
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        DFS(root);
        
        return v;
    }
};
