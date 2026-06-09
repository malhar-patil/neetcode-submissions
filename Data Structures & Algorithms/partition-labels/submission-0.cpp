class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int,int>> m;
        vector<pair<int,int>> arr;

        for(int i=0;i<s.length();i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = {i, INT_MAX};
            }
            else{
                m[s[i]].second = i;
            }
        }
        for(auto iter = m.begin();iter!=m.end();iter++){
            if(iter->second.second == INT_MAX){
                iter->second.second = iter->second.first;
            }
            arr.push_back(iter->second);
        }
        sort(arr.begin(), arr.end());
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i].second == INT_MAX){
        //         arr[i].second == arr[i].first;
        //     }
        // }

        int a = arr[0].first;
        int b = arr[0].second;
        vector<int> ans;
        for(int i=1;i<arr.size();i++){
            if(arr[i].first < b){
                a = min(a, arr[i].first);
                b = max(b, arr[i].second);
            }
            else if(a < arr[i].first){
                ans.push_back(b-a+1);
                a=arr[i].first;
                b=arr[i].second;
            }
            else{
                ans.push_back(arr[i].second-arr[i].first+1);
            }
        }
        ans.push_back(b-a+1);
        return ans;
    }
};
