/**
 * Definition for singly-linked list with a random pointer.
 * struct ListNode {
 *     int val;
 *     ListNode *next, *random;
 *     ListNode(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        if (!head) return head;
        for (auto p = head; p; p = p->next->next) {
            auto q = new ListNode(p->val);
            q->next = p->next;
            p->next = q;
        }
        // 1->1'->2->2'
        for (auto p = head; p; p = p->next->next) {
            if (p->random) {
                p->next->random = p->random->next;
            }
        }
        
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        for (auto p = head; p; p = p->next) {
            cur = cur->next = p->next;
            p->next = p->next->next;
        }
        
        return dummy->next;
    }
};

