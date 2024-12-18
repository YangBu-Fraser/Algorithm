/**
 * 61. Rotate List
 * 
 * Given the `head` of a linked list, rotate the list to the right by `k` places.
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
    ListNode* rotateRight(ListNode* head, int k) {
        int listLength = 1;
        ListNode *p = head;
        while (p -> next) {
            p = p -> next;
            listLength += 1;
        }
        p -> next = head;
        k %= listLength;
        k = listLength - k;
        while (k--) {
            p = p -> next;
        }
        head = p -> next;
        p -> next = nullptr;
        return head;
    }
};