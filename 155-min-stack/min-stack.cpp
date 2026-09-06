class MinStack {
private:
    std::stack<int> st {};
    std::stack<int> min {};
public:
    MinStack() = default;
    
    void push(int value) {
        if(min.empty() || min.top() > value) min.push(value);
        else min.push(min.top()); 
        
        st.push(value);
    }
    
    void pop() {
        min.pop();
        st.pop();
        return;        
    } 
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */