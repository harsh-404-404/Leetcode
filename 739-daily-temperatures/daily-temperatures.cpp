class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> stack {};
        std::vector<int> answer (temperatures.size(), -1);

        for(int i = 0; i < temperatures.size(); ++i){
            if(stack.empty() || temperatures[i] <= stack.top()){
                stack.push(temperatures[i]);
            }else{
                int pop = 0;
                while(!stack.empty() && stack.top() < temperatures[i]){
                    stack.pop();
                    pop++;
                }
                stack.push(temperatures[i]);
                int j = i - 1;
                int days_far = 1;
                while(pop > 0){
                    if(answer[j] == -1){
                        answer[j] = days_far;
                        pop--;
                    }
                    j--;
                    days_far++;
                }
            }
        }
        for(int i = 0; i < answer.size(); ++i){
            if(answer[i] == -1) answer[i] = 0;
        }
        return answer;
    }
    
};