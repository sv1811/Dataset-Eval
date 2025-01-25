class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1!=NULL && temp2!=NULL){
            int sum = temp1->val+temp2->val+carry;
            carry = sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=NULL){
            int sum = temp1->val+carry;
            carry = sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            int sum = temp2->val+carry;
            carry = sum/10;
            temp->next=new ListNode(sum%10);
            temp=temp->next;
            temp2=temp2->next;
        }
        if(carry){
            temp->next=new ListNode(carry);
        }
        return head->next;
    }
};