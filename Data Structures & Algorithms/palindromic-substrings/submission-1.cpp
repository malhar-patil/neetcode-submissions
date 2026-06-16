class Solution {
public:
    int getPalindromeLen(int l, int r, string& s){
        int res = 0;
        while(l>=0 && r<s.length()){    
            if(s[l] != s[r]){
                break;
            }
            l--;
            r++;
            res++;
        }
        return res;
    }
    int countSubstrings(string s) {
        if(s.length() == 1){
            return 1;
        }
        int res = 0;

        for(int i=0;i<s.length();i++){
            //odd length
            int indexes = getPalindromeLen(i,i,s);
            res += indexes;


            //even length
            if(i != s.length()-1){
                indexes = getPalindromeLen(i,i+1,s);
                res += indexes;

            }

        }

        return res;
    }
};
