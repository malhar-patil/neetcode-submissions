class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;

        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]++;
            }
            else{
                m[nums[i]]=1;
            }
        }

        vector<vector<int>> ans(nums.size()+1);
        for(auto iter=m.begin();iter!=m.end();iter++){
            ans[iter->second].push_back(iter->first);
        }

        vector<int> topElem;
        for(int i=ans.size()-1;i>=0 && k>0;i--){
            for(int j=0;j<ans[i].size() && k>0;j++){
                topElem.push_back(ans[i][j]);
                k--;
            }
        }
        return topElem;
    }
};
