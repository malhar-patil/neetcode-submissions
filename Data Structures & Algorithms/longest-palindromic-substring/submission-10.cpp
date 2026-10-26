class Solution {
public:
    pair<int, int> dfs(int i, int j, string& s){
        // if( !(i>=0 && j<s.length()) ){
        //     return 0;
        // }

        while( i>=0 && j<s.length()){
            if(s[i] != s[j]){
                break;
            }

            i--;
            j++;
        }

        return {i+1, (j-1)-(i+1)+1};
    }
    string longestPalindrome(string s) {
        if(s.length() == 1){
            return s;
        }
        int len = 0;
        int start = 0;
        
        for(int i=0;i<s.length()-1;i++){
            pair<int, int> p1 = dfs(i, i, s);
            if(p1.second > len){
                len = p1.second;
                start = p1.first;
            }
            if(s[i] == s[i+1]){
                pair<int, int> p2 = dfs(i, i+1, s);
                if(p2.second > len){
                    len = p2.second;
                    start = p2.first;
                }
            }
        }

        return s.substr(start, len);
    }
};
