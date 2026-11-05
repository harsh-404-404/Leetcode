class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp (amount + 1,-1);
        dp[0] = 0;
        auto solve = [&](auto& self, int make_amount)->int{
            if(dp[make_amount] != -1) return dp[make_amount];

            int min = INT_MAX;
            for(int i = 0; i < coins.size(); ++i){
                if(make_amount < coins[i]) continue;
                int curr = self(self, make_amount - coins[i]);
            
                if(curr == -2) continue;
                min = std::min(min, 1+curr);
            }

            if(min == INT_MAX){
                dp[make_amount] = -2;
                return -2;
            } 
            
            dp[make_amount] = min;
            return min;
        };
        int ans = solve(solve,amount);
        if(ans == -2) return -1;
        return ans;
    }
};