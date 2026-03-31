class Solution {
public:
    string res;
    void solve(string s, int i, int j){
        if( i<0 || j>=s.length()){
            return;
        }
        if(s[i] == s[j]){
            solve(s,i-1,j+1);
        }
        else{
            return;
        }
        if(j-i+1 > res.length()){
            res = s.substr(i,j-i+1);
        }
    }
    string longestPalindrome(string s) {
        if(s.length()==1){
            return s;
        }
        for(int i=0;i<s.length()-1;i++){
            solve(s,i,i);
            solve(s,i,i+1);
        }
        return res;
    }

};
