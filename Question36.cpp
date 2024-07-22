36 -> Multiply Two List

Solution :

/* Linked list node structure
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

/*The method multiplies
two  linked lists l1 and l2
and returns their product*/

/* Multiply contents of two linked lists */
class solution {
  public:
    

/* Linked list node structure
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/

/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

/*You are required to complete this method*/
long long  multiplyTwoLists (Node* l1, Node* l2){
    long long number1=0;
    long long number2=0;
    while(l1!=NULL){
        number1=(number1*10+l1->data)%1000000007;
        l1=l1->next;
    }
    while(l2!=NULL){
        number2=(number2*10+l2->data)%1000000007;
        l2=l2->next;
    }
    return (number1*number2)%1000000007;
}
};