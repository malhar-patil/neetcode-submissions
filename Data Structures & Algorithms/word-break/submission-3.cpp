class Solution {
public:
    unordered_map<int,  bool> memo;
    bool dfs(int index, string&s, unordered_set<string>& m){
        if(index >= s.length()){
            return true;
        }

        if(memo.contains(index)){
            return memo[index];
        }

        string temp;

        for(int i=index;i<s.length();i++){
            temp += s[i];
            if(m.contains(temp)){
                if(dfs(i+1, s, m)){
                    memo[i+1] = true;
                    return true;
                }
            }
        }
        memo[index] = false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> m;
        for(int i=0;i<wordDict.size();i++){
            m.insert(wordDict[i]);
        }
        return dfs(0, s, m);
    }
};
