class Solution {
public:
    int climbStairs(int n) {

        std::vector<int> memo (n + 1, -1);

        auto solve = [&](auto& self, int stairs) -> int{
            
            if(stairs <= 2) return stairs;

            if(memo[stairs] != -1) return memo[stairs];

            return memo[stairs] = self(self, stairs - 1) + self(self, stairs - 2);
        };

        return solve(solve, n);
    }
};