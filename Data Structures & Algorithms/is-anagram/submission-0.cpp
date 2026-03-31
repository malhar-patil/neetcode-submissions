class Solution {
public:
    bool getAns(unordered_map<int,int> bigMap,unordered_map<int,int> smallMap){
        for(auto iter=bigMap.begin();iter!=bigMap.end();iter++){
            if(smallMap.find(iter->first)!=smallMap.end()){
                if(iter->second != smallMap[iter->first]){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
    void solve(unordered_map<int,int> &tempMap,string str){

        for(int i=0;i<str.length();i++){
            if(tempMap.find(str[i])!=tempMap.end()){
                int value=tempMap[str[i]];
                tempMap[str[i]]=value+1;
            }
            else{
                tempMap[str[i]]=1;
            }
        }
    }
    bool isAnagram(string s, string t) {
        unordered_map<int,int> sMap;
        unordered_map<int,int> tMap;
        solve(sMap,s);
        solve(tMap,t);
        if(sMap.size()>tMap.size()){
            return getAns(sMap,tMap);
        }
        else{
            return getAns(tMap,sMap);
        }

    }
};