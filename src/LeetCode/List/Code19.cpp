/**
 * 19. Remove Nth Node From End of List
 * 
 * Given the `head` of a linked list, 
 * remove the `n^th` node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode ret(0, head), *left = &ret, *right = head;
        while (n--) { right = right -> next;}
        while (right) { left = left -> next, right = right -> next;}

        left -> next = left -> next -> next;
        return ret.next;
    }
};