37 -> Palindrome Linked List

Solution :

class Solution {
public:
    ListNode*getmid(ListNode*&head){
        ListNode*fast=head->next;
        ListNode*slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
        
    }
    ListNode*reverse(ListNode*head){
        ListNode*curr=head;
        ListNode*prev=NULL;
        ListNode*forward=NULL;
        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode*mid=getmid(head);
        ListNode*head2=mid->next;
        mid->next=NULL;
        head2=reverse(head2);
        
        while(head2){
            if(head2->val!=head->val)return false;
            head2=head2->next;
            head=head->next;
        }
        return true;
    }
};