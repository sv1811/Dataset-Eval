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
        ListNode* h1=l1;
        ListNode* h2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        int carry=0,sum=0;
        while(h1!=NULL && h2!=NULL){
            sum=h1->val+h2->val;
            int res=sum+carry;
            carry=res/10;
            res=res%10;
            ListNode* temp=new ListNode(res);
            curr->next=temp;
            h1=h1->next;
            h2=h2->next;
            curr=curr->next;
            //carry=sum/10;
        }
       //2 cout << carry << " ";
        if(h1){
            while(h1){
                sum=h1->val;

                int res=sum+carry;
                carry=res/10;
                res=res % 10;
                //cout << res << " ";
                ListNode* temp=new ListNode(res);
                curr->next=temp;
                h1=h1->next;
                curr=curr->next;
                //carry=sum/10;
            }
        }
        if(h2){
            while(h2){
                sum=h2->val;
                int res=sum+carry;
                carry=res/10;
                res=res%10;
                //cout << res;
                ListNode* temp=new ListNode(res);
                curr->next=temp;
                h2=h2->next;
                curr=curr->next;
                //carry=sum/10;
            }
        }
        //cout << carry;
        if(carry){
            ListNode* temp=new ListNode(carry);
            curr->next=temp;
        }    
        return dummy->next;

    }
};