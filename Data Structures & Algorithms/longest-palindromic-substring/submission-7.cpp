class Solution {
public:
    pair<int,int> getPalindromeLen(int l, int r, string& s){
        
        while(l>=0 && r<s.length()){    
            if(s[l] != s[r]){
                break;
            }
            l--;
            r++;
        }
        return {++l, --r};
    }
    string longestPalindrome(string s) {
        if(s.length() == 1){
            return s;
        }
        int resLen = 0;
        int start = 0;

        for(int i=0;i<s.length();i++){
            //odd length
            pair<int, int> indexes = getPalindromeLen(i,i,s);
            if(indexes.second - indexes.first + 1> resLen){
                resLen = indexes.second - indexes.first+1;
                start = indexes.first;
            }

            //even length
            indexes = getPalindromeLen(i,i+1,s);
            if(indexes.second - indexes.first + 1 > resLen){
                resLen = indexes.second - indexes.first +1;
                start = indexes.first;
            }
        }

        return s.substr(start, resLen);
    }
};
