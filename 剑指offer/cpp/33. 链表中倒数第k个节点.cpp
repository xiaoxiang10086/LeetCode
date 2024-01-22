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
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        auto p = pListHead, q = p;
        while (k--) {
            if (q) q = q->next;
            else return NULL;   // 不足K个节点
        }
        while (q) p = p->next, q = q->next;
        return p;
    }
};
