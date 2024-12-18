/**
 * 82. Remove Duplicates from Sorted List II
 * 
 * Given the `head` of a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list. Return the linked list sorted as well.
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;

        // p is left point, q is right point.
        ListNode vritualHead(0, head), *p = &vritualHead, *q;
        while (p->next) {
            if ( p->next->next && p->next->val == p->next->next->val) {
                q = p->next->next;
                while (q && q->val == p->next->val) {
                    q = q->next;
                }
                p->next = q;
            }else {
                p = p->next;
            }
        }
        return vritualHead.next;
    }
};