class Solution {
public:
    string getKey(string s){
        vector<int> arr(26,0);
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
        }

        string res;
        for(int i=0;i<arr.size();i++){
            res+=to_string(arr[i]);
            res+='#';
        }
        // cout<<s<<" "<<res<<endl;
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;

        for(int i=0;i<strs.size();i++){
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto iter=m.begin();iter!=m.end();iter++){
            ans.push_back(iter->second);
        }
        return ans;
    }
};
