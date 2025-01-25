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

   int count(ListNode* l1){
     int cnt = 0;
 ListNode* temp = l1;

while(temp != NULL){
     
     cnt++;
    temp=temp->next;
}

return cnt;
     
   }
    ListNode* addTwoNumbers(ListNode*  l1, ListNode* l2) {
        int n=count(l1);
        int m=count(l2);


       

        if(m>n)return addTwoNumbers(l2,l1);
 ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        
        
        int rem=0;
        int carry=0;

        int sum = 0;

        ListNode* tl=l1;
      // cout<<(l1->val+l2->val)/10;
      while(temp1 != NULL || temp2 != NULL){

tl=temp1;
          int val1=0;
          if(temp1)val1=temp1->val;
          int val2=0;
          if(temp2)val2=temp2->val;

          sum=val1+val2+carry;
          cout<<sum;

          
          temp1->val=sum%10;
          

          carry=sum/10;

           if(temp1)temp1=temp1->next;
             if(temp2)temp2=temp2->next;
      }


if(carry!=0){
    tl->next=new ListNode(carry);
}
      
      return l1;
        
    }

    
};