class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26,0);
        int maxOcc = 0;
        int ans = 0;
        int l=0;

        for(int r=0;r<s.length();r++){
            arr[s[r] - 'A']++;
            maxOcc = max(maxOcc, arr[s[r] - 'A']);

            while((r-l+1) - maxOcc > k){
                arr[s[l] - 'A']--;
                maxOcc = max(maxOcc, arr[s[l] - 'A']);
                l++;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
