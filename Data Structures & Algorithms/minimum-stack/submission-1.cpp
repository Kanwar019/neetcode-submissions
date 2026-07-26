class MinStack {
public:
vector<int> stack;
vector<int> minstack;
    MinStack() {
    }
    
    void push(int val) {
         if(minstack.empty() || val<=minstack.back())
        {
            minstack.push_back(val);
        }
        stack.push_back(val);
    }
    
    void pop() {
        if(minstack.back()== stack.back()){
            minstack.pop_back();
        }
        stack.pop_back();
    }
    
    int top() {
        return stack.back();
    }
    
    int getMin() {
        return minstack.back();
    }
};
