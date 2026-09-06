class MinStack {
private:
    std::stack<int> st {};
    std::multiset<int> min {};
public:
    MinStack() = default;
    
    void push(int value) {
        min.insert(value); 
        st.push(value);
    }
    
    void pop() {
        min.erase(min.find(st.top()));
        st.pop();
        return;        
    } 
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *min.begin();
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