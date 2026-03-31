class Solution {

public:

    bool solve(int index, string& s, unordered_set<string>& st, unordered_map<int, bool>& s2){
        if(s2.find(index) != s2.end()){
            return s2[index];
        }
        if(index >= s.length()){
            return true;
        }

        for(int i=index;i<s.length();i++){
            string temp = s.substr(index, i-index+1);
            if(st.find(temp) != st.end()){
                if(solve(i+1, s, st, s2)){
                    s[index] = true;
                    return true;
                }
            }
        }
        s2[index] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        unordered_map<int, bool> s2;
        return solve(0,s,st,s2);
    }
};