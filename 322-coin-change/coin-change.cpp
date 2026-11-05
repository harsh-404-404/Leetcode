class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int invalid = amount + 1;
        std::vector<int> dp (amount + 1, invalid);
        dp[0] = 0;

        for(int coin : coins){
            if(coin > amount) continue;
            for(int i = coin; i <= amount; ++i){
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
        if(dp[amount] == invalid) return -1;
        return dp[amount];
    }
};