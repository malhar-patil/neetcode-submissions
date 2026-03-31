class Solution {
public:
    void solve(string&s, int i, int j, int& res){
        if(i<0 || j>=s.length() || s[i] != s[j]){
            return;
        }

        if(s[i] == s[j]){
            solve(s,i-1,j+1,res);
        }
        res++;
        return;
    }
    int countSubstrings(string s) {
        int res = 0;
        for(int i=0;i<s.length()-1;i++){
            solve(s,i,i,res);
            solve(s,i,i+1,res);
        }
        solve(s, s.length()-1, s.length()-1, res);
        
        return res;
    }
};
