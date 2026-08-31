class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        for(auto iter=m.begin();iter!=m.end();iter++){
            pq.push({iter->second, iter->first});
        }

        vector<int> ans;
        while(k>0 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
