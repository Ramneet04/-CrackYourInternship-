43 -> Reorder List

Solution :

class Solution {
public:
    ListNode* reverse(ListNode*head){
        ListNode*curr=head;
        ListNode*forward=NULL;
        ListNode*prev=NULL;
        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode*newhead=slow->next;
        slow->next=NULL;
        newhead=reverse(newhead);
        ListNode*curr1=head;
        ListNode*curr2=newhead;
        ListNode*forward1=NULL;
        ListNode*forward2=NULL;
        while(curr1&&curr2){
            forward2=curr2->next;
            forward1=curr1->next;
            curr2->next=curr1->next;
            curr1->next=curr2;
            curr1=forward1;
            curr2=forward2;
        }
    }
};