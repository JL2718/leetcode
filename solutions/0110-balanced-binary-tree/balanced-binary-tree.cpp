// Given a binary tree, determine if it is height-balanced.
//
// For this problem, a height-balanced binary tree is defined as:
//
//
// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
//
//
//  
//
// Example 1:
//
// Given the following tree [3,9,20,null,null,15,7]:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// Return true.
//
// Example 2:
//
// Given the following tree [1,2,2,3,3,null,null,4,4]:
//
//
//        1
//       / \
//      2   2
//     / \
//    3   3
//   / \
//  4   4
//
//
// Return false.
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
    int getDepth(TreeNode* tn,bool& flag){
        if(not tn or flag) return 0;
        int dl = getDepth(tn->left,flag);
        int dr = getDepth(tn->right,flag);
        if(abs(dl-dr)>1)flag=true;
        return 1+max(dl,dr);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(not root) return true;
        bool flag=false;
        getDepth(root,flag);
        return not flag;
    }
};
