class Solution {
public:
    string getString(vector<int> arr){
        string s;
        for(int i=0;i<arr.size();i++){
            s = s + to_string(arr[i]) + '*';
        }
        return s;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++){
            vector<int> arr(26,0);
            for(int j=0;j<strs[i].size();j++){
                arr[strs[i][j]-'a']++;
            }
            string key = getString(arr);
            if(m.find(key)!=m.end()){
                m[key].push_back(strs[i]);
            }
            else{
                vector<string> temp;
                temp.push_back(strs[i]);
                m[key]=temp;
            }
        }

        vector<vector<string>> ans;
        for(auto iter=m.begin();iter!=m.end();iter++){
            ans.push_back(iter->second);
        }
        return ans;
        
    }
};
