class Solution {
public:
    bool isEqual(vector<int>& a1,vector<int>& a2){
        for(int i=0;i<a1.size();i++){
            if(a1[i]!=a2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()){
            return false;
        }
        vector<int> s1Freq(26,0);
        for(int i=0;i<s1.length();i++){
            s1Freq[s1[i]-'a']++;
        }

        vector<int> s2Freq(26,0);
        for(int i=0;i<s1.length();i++){
            s2Freq[s2[i]-'a']++;
        }
        int l=0;
        for(int r=s1.length();r<s2.length();r++){
            if(isEqual(s1Freq,s2Freq)){
                return true;
            }
            s2Freq[s2[l++]-'a']--;
            s2Freq[s2[r]-'a']++;
        }
        if(isEqual(s1Freq,s2Freq)){
            return true;
        }
        return false;
    }
};
