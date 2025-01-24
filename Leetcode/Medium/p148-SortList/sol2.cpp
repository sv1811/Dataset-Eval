// Quick Sort Solution
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode *pivot = head;
        ListNode *smaller = new ListNode(0), *equal = new ListNode(0), *larger = new ListNode(0);
        ListNode *smallerTail = smaller, *equalTail = equal, *largerTail = larger;
        
        ListNode *curr = head;
        while (curr) {
            if (curr->val < pivot->val) {
                smallerTail->next = curr;
                smallerTail = curr;
            } else if (curr->val == pivot->val) {
                equalTail->next = curr;
                equalTail = curr;
            } else {
                largerTail->next = curr;
                largerTail = curr;
            }
            curr = curr->next;
        }
        
        smallerTail->next = nullptr;
        equalTail->next = nullptr;
        largerTail->next = nullptr;
        
        smaller->next = sortList(smaller->next);
        larger->next = sortList(larger->next);
        
        curr = smaller;
