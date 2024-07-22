35 -> Intersection of two list

Solution :

class Solution {
   
public:
    int getlen(ListNode*node){
        int len=0;
        while(node){
            node=node->next;
            len++;}
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
     //   unordered_set<ListNode*>s;
       // while(headA){
  //  s.insert(headA);
    //        headA=headA->next;
 //   }
   //     while(headB){
   //         if(s.find(headB)!=s.end())
    //            return headB;
      //      headB=headB->next;
      //  }
       // return NULL;
        int len1=getlen(headA);
        int len2=getlen(headB);
        ListNode*curr1=headA;
        ListNode*curr2=headB;
        int lendiff=abs(len1-len2);
        if(len1>len2){
            while(lendiff--){
                curr1=curr1->next;
                }
        }
        else{
            while(lendiff--){
                curr2=curr2->next;
            }
        }
        while(curr1&&curr2){
            if(curr1==curr2){
                return curr1;
            }
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
                    
        
    }
};