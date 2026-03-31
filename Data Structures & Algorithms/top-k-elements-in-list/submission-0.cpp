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
        map<int,vector<int>, greater<int>> m2;
        for(auto iter=m.begin();iter!=m.end();iter++){
            m2[iter->second].push_back(iter->first);
        }

        vector<int> ans;
        for(auto iter = m2.begin();iter!=m2.end() && k>0;iter++){
            for(int i=0;i<iter->second.size();i++){
                ans.push_back(iter->second[i]);
                k--;
                if(k<=0){
                    break;
                }
            }
        }
        return ans;
        

    }
};
