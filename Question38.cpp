38 ->  Reverse Linked List

Solution :

class Solution {
public:
    ListNode* reverse(ListNode*head){
        if(head==NULL||head->next==NULL)return head;
        ListNode*prev=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return prev;
    }
    ListNode* reverseList(ListNode* head) {
        head=reverse(head);
        return head;
    }
};