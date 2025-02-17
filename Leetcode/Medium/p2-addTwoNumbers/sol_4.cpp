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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* ptr = dummy;
        int carry = 0;
        int temp;
        while (l1 || l2) {
            temp = carry;
            temp += l1 ? l1->val : 0;
            temp += l2 ? l2->val : 0;
            carry = temp / 10;
            ptr->next = new ListNode(temp % 10);
            ptr = ptr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if (carry) {
                ptr->next = new ListNode(carry);
            }
        return dummy->next;
    }
};




