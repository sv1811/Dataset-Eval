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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        vector<int> nums;
        if(list1==NULL && list2==NULL){
            return nullptr;
        }
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        while(head1!=NULL && head2!=NULL){
            if(head1->val<=head2->val){
                nums.push_back(head1->val);
                head1= head1->next;
            }else{
                nums.push_back(head2->val);
                head2= head2->next; 
            }
        }
        if(head1!=NULL){
            while(head1!=NULL){
                 nums.push_back(head1->val);
                head1= head1->next;
            }
        }
        if(head2!=NULL){
            while(head2!=NULL){
                 nums.push_back(head2->val);
                head2= head2->next;
            }
        }
        ListNode* head = new ListNode(nums[0]);
        ListNode* mover = head;
        for(int i=1; i<nums.size();i++){
              ListNode* temp= new ListNode(nums[i]);
              mover->next=temp;
              mover=temp;
        }
        return head;
    }
};