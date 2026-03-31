class Solution {
public:
    string getString(vector<int> str){
        string s;
        for(int i=0;i<str.size();i++){
            s.append(to_string(str[i]));
            s.append("*");
        }
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            vector<int>arr(26,0);
            for(int j=0;j<strs[i].size();j++){
                arr[strs[i][j]-'a']++;
            }
            m[getString(arr)].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto iter = m.begin();iter!=m.end();iter++){
            res.push_back(iter->second);
        }
        return res;
    }
};
