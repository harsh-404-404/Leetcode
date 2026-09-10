class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        std::stack<int> stack_left {};
        std::stack<int> stack_right {};

        std::vector<int> area (height.size(),0);

        for(int i = 0; i < height.size(); ++i){
            while(!stack_left.empty() && height[stack_left.top()] >= height[i]) stack_left.pop();
            if(stack_left.empty()) area[i] += i * height[i];
            else area[i] += (i - stack_left.top() - 1)* height[i];
            stack_left.push(i);

            int j = height.size() - 1 - i;
            while(!stack_right.empty() && height[stack_right.top()] >= height[j]) stack_right.pop();
            if(stack_right.empty()) area[j] += (i + 1) * height[j];
            else area[j] += (stack_right.top() - j)* height[j];
            stack_right.push(j);
        }

        return *std::max_element(area.begin(),area.end());


    }
};