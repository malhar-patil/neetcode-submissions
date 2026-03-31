class Solution {
public:
    bool isAnagram(string s, string t) {
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

        auto iter1=m1.begin();
        auto iter2=m2.begin();

        while(iter1!=m1.end() && iter2!=m2.end()){
            if(m2.find(iter1->first) == m2.end() || iter1->second != m2[iter1->first]){
                return false;
            }
            iter1++;
            iter2++;
        }
        if(iter1!=m1.end() || iter2!=m2.end()){
            return false;
        }
        return true;
    }
};
