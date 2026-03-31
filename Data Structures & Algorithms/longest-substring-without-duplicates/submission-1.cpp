class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> mySet;
        int l=0;
        int maxLen =0;

        for(int r=0;r<s.length();r++){
            while(mySet.find(s[r])!=mySet.end()){
                mySet.erase(s[l]);
                l++;
            }
            mySet.insert(s[r]);
            maxLen = max(maxLen,r-l+1);
        }

        return maxLen;
    }
};
