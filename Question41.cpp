41 -> Add Two Numbers II

Solution :

class Solution {
public:
    void insertattail(ListNode*&head,ListNode*&tail,int digit){
        ListNode*newnode=new ListNode(digit);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{tail->next=newnode;
             tail=newnode;
            }
    }
    ListNode*sumoftwo(ListNode*first,ListNode*second){
        int carry=0;
        ListNode*anshead=NULL;
        ListNode*anstail=NULL;
        while(first&&second){
            int sum=carry+first->val+second->val;
            int digit=sum%10;
            insertattail(anshead,anstail,digit);
            carry=sum/10;
            first=first->next;
            second=second->next;
        }
        while(first){
            int sum=first->val+carry;
            int digit=sum%10;
            insertattail(anshead,anstail,digit);
            carry=sum/10;
            first=first->next;
        }
        while(second){
            int sum=carry+second->val;
            int digit=sum%10;
            insertattail(anshead,anstail,digit);
            carry=sum/10;
            second=second->next;
        }
        while(carry!=0){
            int sum=carry;
            int digit=sum%10;
            insertattail(anshead,anstail,digit);
            carry=sum/10;
        }
        return anshead;
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
        
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=reverse(l1);
        l2=reverse(l2);
        ListNode*ans=NULL;
        ans=sumoftwo(l1,l2);
        ans=reverse(ans);
        return ans;
    }
};