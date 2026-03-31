class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> m;

        for(int i=0;i<strs.size();i++){
            vector<int> temp(26,0);
            for(int j=0;j<strs[i].size();j++){
                temp[strs[i][j]-'a']++;
            }
            if(m.find(temp)==m.end()){
                vector<string> s;
                s.push_back(strs[i]);
                m[temp]=s; 
            }
            else{
                m[temp].push_back(strs[i]);
            }
        }

        vector<vector<string>> ans;
        for(auto iter=m.begin();iter!=m.end();iter++){
            ans.push_back(iter->second);
        }
        return ans;
    }
};
