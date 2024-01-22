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
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        auto pre = head, cur = pre->next;
        while (cur) {
            auto nxt = cur->next;
            cur->next = pre;
            pre = cur, cur = nxt;
        }
        head->next = NULL;
        return pre;
    }
};
