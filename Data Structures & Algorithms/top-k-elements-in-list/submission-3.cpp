class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        map<int,vector<int>,greater<int>> m2;
        for(auto iter=m.begin();iter!=m.end();iter++){
            if(m2.find(iter->second)!=m2.end()){
                m2[iter->second].push_back(iter->first);
            }
            else{
                vector<int> temp;
                temp.push_back(iter->first);
                m2[iter->second]=temp;
            }
        }

        vector<int> ans;
        for(auto iter=m2.begin();iter!=m2.end() & k>0 ;iter++){
            for(int i=0;i<iter->second.size() & k>0 ;i++){
                ans.push_back(iter->second[i]);
                k--;
            }
        }

        return ans;

    }
};
