46 -> Remove Duplicates from Sorted List II

Solution :

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int,int>m;
        ListNode*curr=head;
        while(curr){
            m[curr->val]++;
            curr=curr->next;  // bs pointer agge badaya hai i++ jaise.
        }
        curr=head;
        ListNode*dummy=new ListNode(-1);
        ListNode*current=dummy;
        while(curr){
            if(m[curr->val]==1){
                ListNode* newnode=new ListNode(curr->val);
                current->next=newnode;
                current=newnode;
            }
            curr=curr->next;
        }
        return dummy->next;
    }
};