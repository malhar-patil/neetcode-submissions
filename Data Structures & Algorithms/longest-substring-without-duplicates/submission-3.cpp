class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1){
            return s.length();
        }
        unordered_map<char,int> m;
        int ans=1;
        int l=0;
        m[s[0]]=1;
        for(int r=1;r<s.length();r++){
            if(m.find(s[r])==m.end()){
                m[s[r]]=1;
            }
            else{
                m[s[r]]++;
            }
            
            while(m[s[r]]>1){
                m[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
