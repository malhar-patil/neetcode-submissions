class Solution {
public:

    int getFreqChar(vector<int>& freq){
        int cnt = 0;
        for(int i=0;i<freq.size();i++){
            cnt=max(cnt, freq[i]);
        }
        return cnt;
    }

    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l=0;
        int ans=0;

        for(int r = 0;r<s.length();r++){
            freq[s[r]-'A']++;
            int freqCnt = getFreqChar(freq);
            int n = (r-l+1) - freqCnt;

            if(n > k){
                freq[s[l]-'A']--;
                l++;
            }

            ans = max(ans, r-l+1);
        }
        return ans;
    }
};
