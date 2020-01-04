// Sort a linked list in O(n log n) time using constant space complexity.
//
// Example 1:
//
//
// Input: 4->2->1->3
// Output: 1->2->3->4
//
//
// Example 2:
//
//
// Input: -1->5->3->4->0
// Output: -1->0->3->4->5
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
    void printList(ListNode *head){
        for(ListNode *n=head;n;n=n->next){
            cout << n->val << " ";
        }
        cout << endl;
    }
    
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        ListNode *r,*l,*p;
        //printList(head);
        r=l=p=head;
        while(p){
            ListNode *n = p->next;
            if(p->val >= head->val){
                r->next = p;
                r = r->next;
            }else{
                p->next = l;
                l = p;
            }
            p = n;
            //printList(p);
        }
        r->next = NULL;
        if(head->next)
            r = sortList(head->next);
        else
            r = NULL;
        head->next = NULL;
        if(l->next)
            l = sortList(l);
        head->next = r;
        //printList(l);
        return l; 
    }
};
