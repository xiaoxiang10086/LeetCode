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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto mid = findMiddleNode(head);
        auto rightHead = mid->next;
        mid->next = NULL;
        auto left = sortList(head);
        auto right = sortList(rightHead);
        return mergeTwoLists(left, right);
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) cur = cur->next = l1, l1 = l1->next;
            else cur = cur->next = l2, l2 = l2->next;
        }
        if (l1) cur = cur->next = l1;
        if (l2) cur = cur->next = l2;
        return dummy->next;
    }

    ListNode* findMiddleNode(ListNode* head) {
        auto s = head, f = head;
        while (f->next && f->next->next) {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
};
