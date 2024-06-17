/**
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
        auto dummy = new ListNode(-1, head);
        auto s = dummy, f = dummy;
        for (int i = 0; i < n+1; i++) {
            f = f->next;
        }
        while (f) {
            s = s->next;
            f = f->next;
        }
        s->next = s->next->next;
        return dummy->next;
    }
};
