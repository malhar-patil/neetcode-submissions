class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(int i=0;i<strs.size();i++){
        s.append(strs[i]);
           s.append("#!");
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        int j=0;

        while(j<s.length()){
            if(s[j]=='#' && s[j+1]=='!'){
                ans.push_back(s.substr(i,j-i));
                i=j+2;
            }
            j++;
        }
        return ans;
    }
};
