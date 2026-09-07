class Solution {
public:
    int evalRPN(vector<string>& tokens){
        std::stack<int> stack {};

        for(std::string s : tokens){
            if(s != "+" && s != "-" && s != "*" && s != "/"){
                stack.push(std::stoi(s));
            }else{
                int temp = stack.top();
                stack.pop();

                if(s == "+") stack.top() += temp; 
                else if(s == "-") stack.top() -= temp;
                else if(s == "*") stack.top() *= temp;
                else if(s == "/") stack.top() /= temp;
            }
            
        } 
        return stack.top();
    }    
};

