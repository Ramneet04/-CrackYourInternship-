42 -> Reverse Linked List II

Solution :

class Solution {
public:
    ListNode*reverse(ListNode*head){
        if(head->next==NULL){
            return head;
        }
        ListNode*newhead=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right)return head;
        ListNode*curr=head;
        ListNode*prev=NULL;
        int count=1;
        
        while(count!=left){
            prev=curr;
            curr=curr->next;
            count++;
        }
        ListNode* start=curr;
        
        while(count!=right){
            curr=curr->next;
            count++;
        }
        ListNode*rest=curr->next;
        curr->next=NULL;
        
        ListNode*reversed=reverse(start);
        
        if(prev){
            prev->next=reversed;
        }
        ListNode*temp=reversed;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=rest;
        
        if(prev==NULL)
            return reversed;
        
        return head;
        
    }
};