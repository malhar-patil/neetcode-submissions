class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(int i=0;i<strs.size();i++){
            ans=ans+strs[i];
            ans=ans+"@!";
        }
        return ans;
    }   

    vector<string> decode(string s) {
        vector<string> ans;
        string temp;
        for(int r=0;r<s.length();r++){
            if(r+1<s.length() && s[r]=='@' && s[r+1]=='!'){
                ans.push_back(temp);
                temp.clear();
                r++;
            }
            else{
                temp+=s[r];
            }
        }
        return ans;
    }
};
