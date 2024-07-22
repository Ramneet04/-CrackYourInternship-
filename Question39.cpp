39 -> Add Two Numbers

Solution :
class Solution {
public:
    void insertattail(ListNode*&head,ListNode*&tail,int digit){
         ListNode* newnode=new ListNode(digit);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    ListNode* getans(ListNode*l1,ListNode*l2){
        int carry=0;
        ListNode*anshead=NULL;
        ListNode*anstail=NULL;
        while(l1!=NULL&&l2!=NULL){
            int sum=carry+l1->val+l2->val;
            int digit=sum%10;
            insertattail(anshead,anstail,digit);
            carry=sum/10;
            l1=l1->next;
            l2=l2->next;
        }
              while(l1!=NULL){
            int sum=carry+l1->val;
            int digit=sum%10;
            insertattail(anshead,anstail,digit);
            carry=sum/10;
            l1=l1->next;
        }
            while(l2!=NULL){
            int sum=carry+l2->val;
            int digit=sum%10;
            insertattail(anshead,anstail,digit);
            carry=sum/10;
            l2=l2->next;
        }
       if(carry!=0){
            insertattail(anshead,anstail,carry);
        }
        return anshead;
        
    }
    // ListNode*reverse(ListNode*head){
    //     if(head==NULL)
    //         return head;
    //     ListNode* curr=head;
    //      ListNode* prev=NULL;
    //      ListNode* forward=NULL;
    //     while(curr!=NULL){
    //         forward=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=forward;
    //     }
    //     return prev;
    // }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        // l1=reverse(l1);
        // l2=reverse(l2);
        ListNode* ans=getans(l1,l2);
        return ans;
        
    }
};