class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1){
            return s.length();
        }
        
        vector<int> arr(128,0);
        int ans = 0;

        int l = 0;
        arr[s[0] - NULL]++;

        for(int r = 1; r < s.length(); r++){
            arr[s[r] - NULL]++;
            while(l < r && arr[s[r] - NULL] > 1){
                arr[s[l] - NULL]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
