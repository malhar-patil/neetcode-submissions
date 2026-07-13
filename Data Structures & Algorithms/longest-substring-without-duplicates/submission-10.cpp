class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> arr(128, 0);
        int len = 0;
        int l=0;
        for(int r=0;r<s.length();r++){
            // if(s[r] == ' '){continue;}
            arr[s[r] - NULL]++;
            while(arr[s[r] - NULL] > 1){
                arr[s[l] - NULL]--;
                l++;
                len = max(len, r-l+1);
            }
            len = max(len, r-l+1);
        }
        return len;
    }
};
