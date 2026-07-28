class MyQueue {
public:
vector<int> stack1;
vector<int> stack2;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack1.push_back(x);
    }
    
    int pop() {
        int front=peek();
        stack2.pop_back();
        return front;

    }
    
    int peek() {
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push_back(stack1.back());
                stack1.pop_back();
            }
        }
        return stack2.back();
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
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