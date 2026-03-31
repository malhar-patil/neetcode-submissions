class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }

        unordered_map<int,int> m1;
        unordered_map<int,int> m2;

        for(int i=0;i<s.length();i++){
            m1[s[i]]++;
            m2[t[i]]++;
        } 

        for(auto iter=m1.begin();iter!=m1.end();iter++){
            if(iter->second!=m2[iter->first]){
                return false;
            }
        }
        return true;
    }
};
