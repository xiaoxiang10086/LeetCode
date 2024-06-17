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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        auto s = head, f = head;
        while (f->next && f->next->next) {
            f = f->next->next;
            s = s->next;
            if (s == f) {
                s = head;
                while (s != f) {
                    s = s->next;
                    f = f->next;
                }
                return s;
            }
        }
        return NULL;
    }
};
