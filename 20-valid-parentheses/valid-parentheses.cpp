class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack {};
        for(auto c : s){
            if(c == '['|| c == '('|| c == '{'){
                stack.push(c);
                continue;
            }

            if(stack.empty()) return false;

            switch(c){
                case ']':
                    if(stack.top() == '['){
                        stack.pop();
                    }else{
                        return false;
                    }
                    break;
                case '}':
                    if(stack.top() == '{'){
                        stack.pop();
                    }else{
                        return false;
                    }
                    break;
                case ')':
                    if(stack.top() == '('){
                        stack.pop();
                    }else{
                        return false;
                    }
                    break;
            }
        }
        if(stack.empty()){
            return true;
        }
        return false;
    }
};