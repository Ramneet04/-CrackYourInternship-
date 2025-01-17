51 ->  Implement Stack using Queues

Solution :

class MyStack {
public:
    MyStack() {
        
    }
    queue<int>q1,q2;
    
    void push(int x) {
        if(q1.empty()){ 
        q1.push(x);
        }
        else{
            while(q1.empty()==0){
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while(q2.empty()==0){
                q1.push(q2.front());
                q2.pop();
            }
        }
        
    }
    
    int pop(){
        
        int ans=q1.front();
        q1.pop();
        
        return ans;
                
                
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()){
            return true;}return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */