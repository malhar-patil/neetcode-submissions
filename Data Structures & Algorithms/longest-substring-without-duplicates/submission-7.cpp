class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1){
            return s.length();
        }
        unordered_map<char,int>m;
        int l=0;
        int maxLen = 0;
        m[s[0]] = 1;
        for(int r=1;r<s.length();r++){
            if(m.find(s[r]) != m.end()){
                m[s[r]]++;
            }
            else{
                m[s[r]] = 1;
            }
            while(m[s[r]] > 1){
                m[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            cout<<l<<" "<<r<<endl;
        }
        return maxLen;
    }
};
