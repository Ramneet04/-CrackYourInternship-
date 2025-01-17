30 -> Remove Duplicates from Sorted List

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
    ListNode* deleteDuplicates(ListNode* head) {
     ListNode*curr=head;
        while(curr&&curr->next){
            if(curr->val==curr->next->val){
                ListNode*nodetodelete=curr->next;
                curr->next=curr->next->next;
                nodetodelete->next=NULL;
                delete nodetodelete;
            }
            else{
            curr=curr->next;
            }
        }
        return head;
    }
};