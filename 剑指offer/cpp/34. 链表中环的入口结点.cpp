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
    ListNode *entryNodeOfLoop(ListNode *head) {
        if (!head) return NULL;
        auto s = head, f = s;
        while (f && f->next) {
            s = s->next;
            f = f->next->next;
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