// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its bottom-up level order traversal as:
//
// [
//   [15,7],
//   [9,20],
//   [3]
// ]
//
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
private:
    vector<vector<int>> vvv;
    void dfs(TreeNode* t,int d=0){
        if(t){
            if(vvv.size()<=d) vvv.resize(d+1);
            vvv[d].push_back(t->val);
            dfs(t->left,d+1);
            dfs(t->right,d+1);
        }
    }
public:
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        dfs(root);
        return vector<vector<int>>(vvv.rbegin(),vvv.rend());
    }
};
