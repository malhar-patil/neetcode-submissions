class Solution {
public:
    int x=0;
    int len=0;
    void solve(string& s, int i, int j){
        if( i<0 || j>=s.length()){
            return;
        }
        if(s[i] == s[j]){
            solve(s,i-1,j+1);
        }
        else{
            return;
        }
        if(j-i+1 > len){
            x=i;
            len = j-i+1;
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
        return s.substr(x,len);
    }

};
