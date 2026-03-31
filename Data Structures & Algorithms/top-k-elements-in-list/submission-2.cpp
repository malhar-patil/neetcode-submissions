class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]++;
            }
            else{
                m[nums[i]]=1;
            }
        }

        vector<vector<int>> v (nums.size()+1, vector<int>(1,INT_MIN));
        for(auto iter=m.begin();iter!=m.end();iter++){
            v[iter->second].push_back(iter->first);
        }

        for(int i=v.size()-1;i>=0 && k>0;i--){
            for(int j=0;j<v[i].size()&& k>0;j++){
                if(v[i][j]!=INT_MIN){
                    ans.push_back(v[i][j]);
                    k--;
                }
            }
        }

        return ans;

    }
};
