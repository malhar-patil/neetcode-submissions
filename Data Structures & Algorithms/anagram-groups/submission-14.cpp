class Solution {
public:
    string getKey(string& s){
        string res;
        vector<int> cnt(26,0);
        for(int i=0;i<s.length();i++){
            cnt[s[i]-'a']++;
        }

        for(int i=0;i<cnt.size();i++){
            res+= "#";
            res+= to_string(cnt[i]);
        }

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
