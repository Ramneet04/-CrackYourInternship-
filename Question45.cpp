45 -> Partition List

Solution :

class Solution {
public:
    void insertatlast(ListNode*&anshead,ListNode*&anstail,int x){
        ListNode*newnode=new ListNode(x);
        if(anshead==NULL){
            anshead=newnode;
            anstail=newnode;
            return;
        }
        else{
            anstail->next=newnode;
            anstail=newnode;
            return;
        }
    }
    void solve(ListNode*& head,ListNode*&anshead, ListNode*&anstail,ListNode*&anshead2,ListNode*&anstail2,int x){
        ListNode*curr=head;
        while(curr){
            if(curr->val<x){
                insertatlast(anshead,anstail,curr->val);
            }
            else{
                insertatlast(anshead2,anstail2,curr->val);
            }
            curr=curr->next;
        }
    }
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL)return head;
     ListNode*small=NULL;
        ListNode*smallTail=NULL;
     ListNode*large=NULL;
        ListNode*largeTail=NULL;
      solve(head,small,smallTail,large,largeTail,x);
        if(smallTail==NULL)return large;
        smallTail->next=large;
        return small;
    }
};