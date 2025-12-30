class MyQueue {
stack<int>s1;
stack<int>s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()&&!s1.empty()){
            //o(n)
            while(!s1.empty()){
            int top=s1.top();
            s1.pop();
            s2.push(top);
        }
        int pop=s2.top();
        s2.pop();
        return pop;
    }
    else if(!s2.empty()){
        int pop=s2.top();
        s2.pop();
        return pop;
    }
    return -1;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                int top=s1.top();
                s1.pop();
                s2.push(top);
            }
            return s2.top();
        }
        else{
            return s2.top();
        }
        return -1;
    }
    
    bool empty() {
        if(s1.empty()&&s2.empty()){
            return true;
        }
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