class Solution {
public:
    string hash(vector<int> arr){
        string s;
        for(int i=0;i<arr.size();i++){
            s=s+to_string(arr[i])+'#';
        }
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;

        for(int i=0;i<strs.size();i++){
            vector<int>temp(26,0);
            for(int j=0;j<strs[i].length();j++){
                temp[strs[i][j]-'a']++;
            }
            string s = hash(temp);
            if(m.find(s)!=m.end()){
                m[s].push_back(strs[i]);
            }
            else{
                vector<string> sTemp;
                sTemp.push_back(strs[i]);
                m[s] = sTemp;
            }
        }

        vector<vector<string>> ans;
        for(auto iter=m.begin();iter!=m.end();iter++){
            ans.push_back(iter->second);
        }
        return ans;

    }
};
