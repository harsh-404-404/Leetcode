class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int row = prerequisites.size();
        std::vector<std::vector<int>> preqlist (numCourses);
        for(int i = 0; i < row; ++i){
            preqlist[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        std::vector<bool> checklist (numCourses, false);
        std::vector<bool> do_not_visite (numCourses, false);

        auto dfs = [&](auto& self, int curr_course)->bool{
            if(do_not_visite[curr_course]) return false;
            do_not_visite[curr_course] = true;
            for(int i : preqlist[curr_course]){
                if(checklist[i]) continue;
                if(!self(self, i)) return false;
            }
            do_not_visite[curr_course] = false;
            checklist[curr_course] = true;
            return true;
        };

        for(int i = 0; i < numCourses; ++i){
            if(!checklist[i] && !dfs(dfs,i)){
                return false;
            }
        }
        return true;
    }
};