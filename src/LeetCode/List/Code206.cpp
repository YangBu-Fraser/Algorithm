/**
 * 206. Reverse Linked List
 * Given the `head` of a singly linked list, reverse the list, and return the reversed list.
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
    ListNode* reverseList(ListNode* head) {
        /* version 1
        if(head == nullptr) return head;
        ListNode *pre = nullptr, *cur = head, *p = head -> next;
        while(cur) {
            cur -> next = pre;
            pre = cur;
            (cur = p) && (p = p -> next);
        }

        return pre;
        */
        
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode *tail = head -> next, *p = reverseList(head -> next);
        head -> next = tail -> next;
        tail -> next = head;
        return p;
        
    }
};