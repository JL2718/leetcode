// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
//
//  
//
// But the following [1,2,2,null,3,null,3] is not:
//
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
//
//  
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.
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
    bool isMirror(TreeNode* lt,TreeNode* rt){
        if(not lt and not rt) return true;
        if(not lt or not rt) return false;
        if(lt->val==rt->val)
            return(isMirror(lt->left,rt->right) and isMirror(lt->right,rt->left));
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(not root) return true;
        if(not root->left and not root->right) return true;
        if(not root->left or not root->right) return false;
        return isMirror(root->right,root->left);
    }
};
