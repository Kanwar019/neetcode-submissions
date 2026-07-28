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
        int front=stack1.front();
        stack1.erase(stack1.begin());
        return front;

    }
    
    int peek() {
        return stack1.front();
    }
    
    bool empty() {
        if(stack1.empty()){
            return true;
        }else{
            return false;
        }
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