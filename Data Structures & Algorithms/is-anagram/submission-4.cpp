class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        int i = 0;
        int j = 0;

        while(i<s.length() && j<t.length()){
            if(m1.find(s[i])!=m1.end()){
                m1[s[i++]]++;
            }
            else{
                m1[s[i++]]=1;
            }

            if(m2.find(t[j])!=m2.end()){
                m2[t[j++]]++;
            }
            else{
                m2[t[j++]]=1;
            }
        }

        while(i<s.length()){
            if(m1.find(s[i])!=m1.end()){
                m1[s[i++]]++;
            }
            else{
                m1[s[i++]]=1;
            }   
        }

        while(j<t.length()){
            if(m2.find(t[j])!=m2.end()){
                m2[t[j++]]++;
            }
            else{
                m2[t[j++]]=1;
            }  
        }

        for(auto iter=m1.begin();iter!=m1.end();iter++){
            if(iter->second != m2[iter->first]){
                return false;
            }
        }
        return true;
    }
};
