class MinStack {
private:
    std::stack<std::pair<int,int>> st {};
public:
    MinStack() = default;
    
    void push(int value) {
        if(st.empty() || st.top().second > value) st.emplace(value,value);
        else st.emplace(value,st.top().second); 
    }
    
    void pop() {
        st.pop();
        return;        
    } 
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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