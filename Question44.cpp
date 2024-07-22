44 -> Remove Nth Node From End of List

Solution :

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*fast=head;
        ListNode*slow=head;
        int count=0;
        while(count<n){
            fast=fast->next;
            count++;
        }
        if(fast==NULL)return head->next;
        
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow->next==NULL){
            slow->next=NULL;
            return head;
        }
        slow->next=slow->next->next;
        return head;
    }
};