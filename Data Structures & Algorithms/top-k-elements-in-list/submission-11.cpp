class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        for(auto iter=m.begin();iter!=m.end();iter++){
            if(pq.size() < k){
                pq.push({iter->second, iter->first});
                continue;
            }

            if(pq.size() >= k && iter->second > pq.top().first){
                pq.pop();
                pq.push({iter->second, iter->first});
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
