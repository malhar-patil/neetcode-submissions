class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        int maxLen=0;
        int l=0;
        int maxFreq=0;
        for(int r=0;r<s.length();r++){
            m[s[r]]++;
            maxFreq = max(maxFreq, m[s[r]]);
            while((r-l+1)-maxFreq > k){
                m[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
