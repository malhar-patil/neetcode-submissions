class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> m;
        vector<int> arr;

        for(int i=0;i<strs.size();i++){
            arr.assign(26,0);
            for(int j=0;j<strs[i].size();j++){
                arr[strs[i][j]-97]++;
            }
            m[arr].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto iter=m.begin();iter!=m.end();iter++){
            vector<string> temp;
            for(int i=0;i<iter->second.size();i++){
                temp.push_back(iter->second[i]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
