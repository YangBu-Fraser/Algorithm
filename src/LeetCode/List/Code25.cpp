/**
 * 25. Reverse Nodes in k-Group
 * 
 * Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return the modified list.
 * `k` is a positive integer and is less than or equal to the length of the linked list. 
 * If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
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
    ListNode *__reverseNode(ListNode *head, int n) {
        if (n == 1) return head;
        ListNode *tail = head -> next, *p = __reverseNode(head -> next, n-1);
        head -> next = tail -> next;
        tail -> next = headl
        return p;
    }

    ListNode *reverseNode(ListNode *head, int n) {
        ListNode *p = head;
        int cnt = n;
        while (--n && p) p = p -> next;
        if (p == nullptr) return nullptr;
        return __reverseNode(head, cnt);
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode ret(0, head), *p = &ret, *q = p -> next;
        while (p -> next = reverseNode(q, k)) {
            p = q;
            q = p -> next;
        }
        return ret.next;
    }
};