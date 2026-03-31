class Solution {
public:
    bool isMatch(unordered_map<char,int>& arr1, unordered_map<char,int>& arr2){
        for(auto iter=arr1.begin();iter!=arr1.end();iter++){
            if(arr2.find(iter->first) == arr2.end()){
                return false;
            }
            if(arr1[iter->first] > arr2[iter->first]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.length() < t.length()){
            return "";
        }

        unordered_map<char,int> arr1;
        for(int i=0;i<t.length();i++){
            arr1[t[i]]++;
        }
        unordered_map<char,int> arr2;
        int x=0;
        int len=INT_MAX;
        int l=0;
        for(int r=0;r<s.length();r++){
            arr2[s[r]]++;
            while(r-l+1 >= t.length() && isMatch(arr1,arr2)){
                if(r-l+1 < len){
                    x=l;
                    len=r-l+1;
                }
                arr2[s[l]]--;
                l++;
            }
        
        }
        if(x==0 && len==INT_MAX){
            return "";
        }
        return s.substr(x,len);
    }
};
