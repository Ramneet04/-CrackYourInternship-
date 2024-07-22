40 ->  Copy List with Random Pointer

Solution :

class Solution {
public:
    void insertattail(Node*&head,Node*&tail,int data){
        Node* newnode=new Node(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    Node* copyRandomList(Node* head) {
        Node*curr=head;
        Node*anshead=NULL;
        Node*anstail=NULL;
        while(curr){
            insertattail(anshead,anstail,curr->val);
            curr=curr->next;
            
        }
        curr=head;
        Node*temp=anshead;
       unordered_map<Node*,Node*>m;
        while(curr&&temp){
            m[curr]=temp;
            curr=curr->next;
            temp=temp->next;
        }
        curr=head;
        temp=anshead;
        while(temp){
            temp->random=m[curr->random];
            temp=temp->next;
            curr=curr->next;
        }
        return anshead;
        
    }
};