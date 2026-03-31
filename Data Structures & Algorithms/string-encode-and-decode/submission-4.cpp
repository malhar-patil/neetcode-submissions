class Solution {
public:

    string encode(vector<string>& strs) {
        string temp="";
        for(int i=0;i<strs.size();i++){
            temp+=strs[i];
            temp+="/";
        }

        return temp;

    }

    vector<string> decode(string s) {
        vector<string> ans;
        string temp;
        for(int i=0;i<s.length();i++){
            if(s[i]!='/'){
                temp+=s[i];
            }
            else{
                ans.push_back(temp);
                temp="";
            }
        }
        return ans;
    }
};
