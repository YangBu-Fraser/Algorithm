/**
 * 92. Reverse Linked List II
 * 
 * Given the head of a singly linked list and two integers left and right where left <= right, 
 * reverse the nodes of the list from position left to position right, and return the reversed list.
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
    ListNode* preReverse(ListNode *head, int n) {
        if (n == 1) return head;
        ListNode *tail = head -> next, *p = preReverse(head->next, n-1);
        head -> next = tail -> next;
        tail -> next = head;
        return p;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode ret(0, head), *p =&ret;    // virtual node.
        int cnt = right - left + 1;
        while(--left) p = p -> next;
        p -> next = preReverse(p -> next, cnt);
        return ret.next;
    }
};