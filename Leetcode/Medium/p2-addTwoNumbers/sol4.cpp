
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode;
        ListNode* ans=temp;
        int carry=0;
        while(l1!=nullptr&&l2!=nullptr){
            int t=l1->val+l2->val+carry;
            carry=0;
            if(t>9) carry=1;
            t=t%10;
            temp->val=t;
            l1=l1->next; l2=l2->next;
            if(l1==nullptr&&l2==nullptr&&carry==0) break;
            ListNode* a=new ListNode;
            temp->next=a;
            temp=a;
            if(l1==nullptr&&l2==nullptr&&carry==1) {temp->val=1; break;}
        }
        while(l1!=nullptr){
            int t=l1->val+carry;
            carry=0;
            if(t>9) carry=1;
            t=t%10;
            temp->val=t;
            if(l1->next==nullptr&&carry==0) break;
            ListNode* a=new ListNode;
            temp->next=a;
            temp=a;
            l1=l1->next;
        }
        if(carry) {temp->val=carry; carry=0;}
        while(l2!=nullptr){
            int t=l2->val+carry;
            carry=0;
            if(t>9) carry=1;
            t=t%10;
            temp->val=t;
            
            if(l2->next==nullptr&&carry==0) break;
            ListNode* a=new ListNode;
            temp->next=a;
            temp=a;
            l2=l2->next;
        }
        if(carry) {temp->val=1;}
return ans;
        
    }
};