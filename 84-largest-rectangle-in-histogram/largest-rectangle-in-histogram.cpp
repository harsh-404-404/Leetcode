class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        std::stack<int> stack {};
        int ans = 0;

        for(int i = 0; i <= height.size(); ++i){
            
            int curr = (i == height.size()) ? 0 : height[i];

            while(!stack.empty() && height[stack.top()] >= curr){
                int h = height[stack.top()];                
                stack.pop();

                int left = (stack.empty()) ? -1 : stack.top(); 

                int width = i - 1 - left;
                
                ans = std::max(width*h, ans);
            }

            stack.push(i);
        }
        return ans;
    }
};