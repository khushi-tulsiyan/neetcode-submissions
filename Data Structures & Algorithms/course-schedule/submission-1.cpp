class Solution {
    unordered_map<int, vector<int>> prepMap;
    unordered_set<int> visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i = 0; i<numCourses; i++){
            prepMap[i] = {};
        }
        for(const auto &prereq : prerequisites){
            prepMap[prereq[0]].push_back(prereq[1]);
        }

        for(int c= 0; c< numCourses; c++){
            if(!dfs(c)){
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs){
        if(visiting.count(crs)){
            return false;
        }
        if(prepMap[crs].empty()){
            return true;
        }

        visiting.insert(crs);
        for(int pre: prepMap[crs]){
            if(!dfs(pre)){
                return false;
            }
        }
        visiting.erase(crs);
        prepMap[crs].clear();
        return true;
    }
};
