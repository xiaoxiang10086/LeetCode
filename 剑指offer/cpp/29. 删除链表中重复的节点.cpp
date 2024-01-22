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
    ListNode* deleteDuplication(ListNode* head) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        
        auto cur = dummy;
        while (cur->next) {
            auto end = cur->next;
            while (end && cur->next->val == end->val) end = end->next;
            
            if (cur->next->next == end) cur = cur->next;
            else cur->next = end;
        }
        
        return dummy->next;
    }
};
