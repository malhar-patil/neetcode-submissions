class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<vector<int>> temp(nums.size()+1);
        for(auto iter = m.begin();iter!=m.end();iter++){
            temp[iter->second].push_back(iter->first);
        }
        vector<int> res;
        for(int i=temp.size()-1;i>=0 && k>0;i--){
            for(int j=0;j<temp[i].size() && k>0 ;j++){
                res.push_back(temp[i][j]);
                k--;
            }
        }
        return res;
    }
};
