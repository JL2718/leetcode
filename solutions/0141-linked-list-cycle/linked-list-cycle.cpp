// Given a linked list, determine if it has a cycle in it.
//
// To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
//
//  
//
//
// Example 1:
//
//
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where tail connects to the second node.
//
//
//
//
//
//
// Example 2:
//
//
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where tail connects to the first node.
//
//
//
//
//
//
// Example 3:
//
//
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.
//
//
//
//
//
//  
//
// Follow up:
//
// Can you solve it using O(1) (i.e. constant) memory?
//


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(not head or not head->next) return false;
        auto p=head,q=head->next;
        for(int i=0;p and q and p!=q;++i){
            if(i%2) p=p->next;
            q=q->next;
        }
        return (p and q and p==q);
    }
};
