class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        std::vector<std::pair<int, int>> ps;
        ps.reserve(position.size());

        for(int i = 0; i < position.size(); ++i){
            ps.emplace_back(position[i],speed[i]);
        }

        std::sort(ps.begin(),ps.end());

        std::stack<double> stack {};

        int ans {0};
        for(int i = position.size() - 1; i >= 0; --i){
            double time_to_reach = (target - ps[i].first)/static_cast<double>(ps[i].second);
            if(stack.empty()){
                stack.push(time_to_reach);
            }else if(time_to_reach <= stack.top()){
                stack.push(stack.top());
            }else{
                while (!stack.empty()) stack.pop();
                ans++;
                stack.push(time_to_reach);
            }
        }

        return ++ans;
    }
};