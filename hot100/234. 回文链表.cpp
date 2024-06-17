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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = findMiddleNode(head);
        ListNode* rightHead = reverse(mid->next);
        return cmp(head, rightHead);
    }

    ListNode* findMiddleNode(ListNode* head) {
        auto s = head, f = head;
        while (f->next && f->next->next) {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }

    ListNode* reverse(ListNode* head) {
        if (!head || !head->next) return head;
        auto pre = head, cur = head;
        while (cur) {
            auto nxt = cur->next;
            cur->next = pre;
            pre = cur, cur = nxt;
        }
        head->next = NULL;
        return pre;
    }

    bool cmp(ListNode* p, ListNode* q) {
        while (p && q) {
            if (p->val != q->val) {
                return false;
            }
            p = p->next;
            q = q->next;
        }
        return true;
    }
};
