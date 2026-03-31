class Solution {
public:
    void solve(vector<int> candidates, int target,vector<vector<int>>& ans,vector<int> temp,int index, int sum){
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(index>=candidates.size() || sum>target){
            return;
        }

        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
            solve(candidates,target,ans,temp,i+1,sum+candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,target,ans,temp,0,0);
        return ans;
    }
};
// 1 2 2 4 5 6 9   target = 8;
