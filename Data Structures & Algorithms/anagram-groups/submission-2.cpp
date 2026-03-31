class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,vector<string>> m;

        for(int i=0;i<strs.size();i++){
            vector<int> temp(26,0);
            for(int j=0;j<strs[i].size();j++){
                temp[strs[i][j]-'a']++;
            }
            if(m.find(temp)!=m.end()){
                m[temp].push_back(strs[i]);
            }
            else{
                vector<string> temp2;
                temp2.push_back(strs[i]);
                m[temp]=temp2;
            }
        }

        for(auto iter=m.begin();iter!=m.end();iter++){
            ans.push_back(iter->second);
        }

        return ans;
    }
};
