47 -> Sort List

Solution :

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode*curr=head;
        while(curr!=NULL){
            arr.push_back(curr->val);
            curr=curr->next;
        }
        curr=head;
        sort(arr.begin(),arr.end());
        for(int i=0;
           i<arr.size();
           i++){
            curr->val=arr[i];
            curr=curr->next;
        }
        return head;
    }
};