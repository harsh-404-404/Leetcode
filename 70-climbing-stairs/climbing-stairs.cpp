class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        std::vector<int> steps (n + 1,0);
        steps[1] = 1;
        steps[2] = 2;
        int last_known = 2;
        auto solve = [&](auto& self, int stairs)-> int{
            if(stairs <= last_known){
                return steps[stairs];
            }
            steps[stairs] = self(self, stairs - 1) + self(self, stairs - 2);
            last_known = stairs;
            return steps[stairs]; 
        };

        solve(solve, n);
        return steps[n];
    }
};