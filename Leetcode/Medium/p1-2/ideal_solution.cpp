
 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int overflow = 0;
        ListNode* result = nullptr;
        ListNode* current;
        while((l1 && l2) || overflow){
            int val1 = l1? l1->val : 0;
            int val2 = l2? l2->val : 0;
            ListNode* new_digit = new ListNode((val1 + val2 + overflow) % 10);
            overflow = (val1 + val2 + overflow) / 10;
            if(!result){
                result = new_digit;
                current = new_digit;
            }else{
                current->next = new_digit;
                current = current->next;
            }
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(l1) current->next = l1;
        if(l2) current->next = l2;
        return result;
    }
};