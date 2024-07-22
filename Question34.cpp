34 -> Delete nodes having greater value on right


Solution :

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* reverse(Node*head){
            Node*curr=head;
        Node*prev=NULL;
        Node*forward=NULL;
        while(curr){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    void insertatFirst(int data,Node*&ans,Node*&anshead){
        if(ans==NULL){
            Node* newnode = new Node(data);
            ans=newnode;
            anshead=newnode;
        }
        else{
            Node* newnode = new Node(data);
            newnode->next=anshead;
            anshead=newnode;
        }
    }
    Node *compute(Node *head)
    {
        head=reverse(head);
        Node*ans=NULL;
        Node*anshead=NULL;
        
        Node*curr=head;
        int prev=curr->data;
        
        while(curr){
            if(curr->data>=prev){
                insertatFirst(curr->data,ans,anshead);
            }
            prev=max(prev,curr->data);
            curr=curr->next;
        }
        return anshead;
        
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends