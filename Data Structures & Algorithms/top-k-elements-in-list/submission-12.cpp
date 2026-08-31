class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        vector<vector<int>> freq(nums.size()+1);

        for(auto iter=m.begin();iter!=m.end();iter++){
            freq[iter->second].push_back(iter->first);
        }

        vector<int> ans;

        for(int i=freq.size()-1;i>=0 && k>0;i--){
            for(int j=0;j<freq[i].size() && k>0;j++){
                ans.push_back(freq[i][j]);
                k--;
            }
        }

        return ans;
    }
};
