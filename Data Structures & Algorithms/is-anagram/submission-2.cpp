class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;

        for(int i=0;i<s.length();i++){
            if(m1.find(s[i])!=m1.end()){
                m1[s[i]]++;
            }
            else{
                m1[s[i]] = 1;
            }
        }

        for(int i=0;i<t.length();i++){
            if(m2.find(t[i])!=m2.end()){
                m2[t[i]]++;
            }
            else{
                m2[t[i]] = 1;
            }
        }

        for(auto iter=m1.begin();iter!=m1.end();iter++){
            if(m2.find(iter->first) == m2.end() || iter->second != m2[iter->first]){
                return false;
            }
        }

        return true;
    }
};
