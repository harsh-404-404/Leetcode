class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int take2step = 0;
        int take1step = 0;

        for(int i = cost.size()-1; i >= 0; i--){
            int curr = cost[i] + std::min(take2step,take1step);
            take2step = take1step;
            take1step =  curr;
        }

        return std::min(take1step,take2step);

    }
};