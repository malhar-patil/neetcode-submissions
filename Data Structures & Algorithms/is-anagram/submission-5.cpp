class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1;
        vector<int> v2;

        v1.assign(26,0);
        v2.assign(26,0);

        for(int i=0;i<s.length();i++){
            v1[s[i]-97]++;
        }

        for(int i=0;i<t.length();i++){
            v2[t[i]-97]++;
        }

        for(int i=0;i<v1.size();i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;
    }
};
