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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode(-1, head);
        auto cur = dummy;
        while (cur != NULL) {
            auto end = cur;
            for (int i = 0; i < k && end != NULL; i++) {
                end = end->next;
            }
            if (end == NULL) {
                break;
            }

            auto p = cur->next, q = p->next;
            for (int i = 0; i < k-1; i++) {
                auto nxt = q->next;
                q->next = p;
                p = q, q = nxt;
            }

            auto c = cur->next;
            cur->next = p;
            c->next = q;
            cur = c;
        }

        return dummy->next;
    }
};
