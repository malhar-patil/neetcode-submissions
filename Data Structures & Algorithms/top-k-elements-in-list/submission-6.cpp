class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> arr(nums.size()+1,vector<int>());
        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto iter=m.begin();iter!=m.end();iter++){
            arr[iter->second].push_back(iter->first);
        }

        vector<int>ans;
        for(int i=arr.size()-1;i>=0 && k>0;i--){
            for(int j=arr[i].size()-1 ;j>=0 && k>0;j--){
                ans.push_back(arr[i][j]);
                k--;
            }
        }
        return ans;
    }
};
