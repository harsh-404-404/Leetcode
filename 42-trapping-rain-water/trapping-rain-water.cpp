class Solution {
public:
    int trap(vector<int>& height) {
        int a = 0;
        int b = height.size() - 1;
        int ans = 0;
        while(a < b){
            int low = std::min(height[a], height[b]);
            if(low == height[a]){
                a++;
                while(a < b && height[a] <= low){
                    ans += low - height[a];
                    a++;
                }
            }else{
                b--;
                while(a < b && height[b] <= low){
                    ans += low - height[b];
                    b--;
                }        
            }
            
        }
        return ans;
    }
};