30 -> Convert Binary Number in a Linked List to Integer

Solution : 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode*reverse(ListNode*head){
        if(head==NULL)return head;
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
    int getDecimalValue(ListNode* head) {
        head=reverse(head);
        ListNode*curr=head;
        int ans=0,i=0;
        while(curr){
            ans=ans+pow(2,i)*curr->val;
            i++;
            curr=curr->next;
        }
        return ans;
    }
};