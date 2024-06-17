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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(-1);
        auto cur = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) cur = cur->next = l1, l1 = l1->next;
            else cur = cur->next = l2, l2 = l2->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return dummy->next;
    }

    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        int mid = l + r >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) return NULL;
        return merge(lists, 0, n-1);
    }
};
