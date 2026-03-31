class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            s+=temp;
            s+='/';
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='/'){
                ans.push_back(temp);
                temp="";
            }
            else{
                temp+=s[i];
            }
        }

        return ans;
    }
};
