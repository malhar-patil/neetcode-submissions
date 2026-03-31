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

        map<int, vector<int>,greater<int>> n;
        for(auto iter = m.begin();iter!=m.end();iter++){
            if(n.find(iter->second)==n.end()){
                vector<int> temp;
                temp.push_back(iter->first);
                n[iter->second] = temp;
            }
            else{
                n[iter->second].push_back(iter->first);
            }
        }

        vector<int> ans;
        for(auto iter=n.begin();iter!=n.end() && k>0;iter++){
            for(int i=0;i<iter->second.size()&& k>0;i++){
                ans.push_back(iter->second[i]);
                k--;
            }
        }
        return ans;

    }
};
