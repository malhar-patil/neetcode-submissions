class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==1){return 1;}
        vector<int>freq(128, 0);
        int l=0;
        int ans = 0;
        for(int r=0;r<s.length();r++){
            freq[s[r] - NULL]++;
            while(freq[s[r] - NULL] > 1){
                freq[s[l] - NULL]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
