49 -> Implement Queue using Stacks

Solution :

class MyQueue {
public:
    stack<int>s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
            s1.push(x);
        }
        else{
            s2.push(x);
        }
    }
    
    int pop() {
        int ans=s1.top();
        s1.pop();
        if(s1.empty()){
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        }
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if(s1.empty()&&s2.empty())return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */