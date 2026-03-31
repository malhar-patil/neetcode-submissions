class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(int i=0;i<strs.size();i++){
            s = s + strs[i] + "#!";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='#' && i+1<=s.length()-1 && s[i+1]=='!'){
                ans.push_back(temp);
                i++;
                temp.clear();
            }
            else{
                temp = temp + s[i];
            }
        }
        return ans;
    }
};
