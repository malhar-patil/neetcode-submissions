class Solution {
public:
    string encode(vector<string>& strs) {
        string s;
        for(int i=0;i<strs.size();i++){
            s+=strs[i];
            s+="?!";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        if(s.length()==0){
            return ans;
        }
        string temp;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]!='?' && s[i+1]!='!'){
                temp+=s[i];
            }
            else{
                ans.push_back(temp);
                i=i+1;
                temp.clear();
            }
        }
        return ans;
    }
};
