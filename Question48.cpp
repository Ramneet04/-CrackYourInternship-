48 -> Reverse Nodes in K Groups

Solution :
class Solution {
public:
 int getlength( ListNode* head){
      ListNode*temp=head;
      int count=0;
      while(temp!=NULL){
          temp=temp->next;
          count++;
      }
      return count;
 }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
         ListNode*curr=head;
          ListNode*prev=NULL;
           ListNode*forward=NULL;
           int count=0;
           while(curr!=NULL&&count<k){
               forward=curr->next;
               curr->next=prev;
               prev=curr;
               curr=forward;
               count++;
           }
            int len=getlength(curr);
           if(len>=k){
           if(curr!=NULL){
           head->next=reverseKGroup(curr,k);  
               }
           }
           else{
           head->next=curr;
           }
           return prev;
    }
};