// Given a binary tree, return the inorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [1,3,2]
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return vector<int>{};
        else
            return vcat(
                inorderTraversal(root->left),
                vector<int>{root->val},
                inorderTraversal(root->right))
            ;
    }
    vector<int> vcat(vector<int> a,vector<int> b,vector<int> c){
        vector<int> r;
        copy(begin(a),end(a),back_inserter(r));
        copy(begin(b),end(b),back_inserter(r));
        copy(begin(c),end(c),back_inserter(r));
        return r;
    }
};
