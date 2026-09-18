class Solution {
public:

    void solve(vector<int>& candidates, int target, int index,
               vector<int>& current, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        if (target < 0 || index == candidates.size()) {
            return;
        }
        current.push_back(candidates[index]);

        
        solve(candidates, target - candidates[index],
              index, current, ans);

        // Backtrack
        current.pop_back();

        // Skip candidates[index]
        solve(candidates, target, index + 1,
              current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates, target, 0, current, ans);

        return ans;
    }
};