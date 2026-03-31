class Solution {
public:
    bool isValid(vector<int>arr1,vector<int>arr2){
        for(int i=0;i<128;i++){
            if(arr2[i]<arr1[i]){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        if(s.length()<t.length()){
            return "";
        }

        int minLen=INT_MAX;
        int startIndex=-1;
        vector<int>arr1(128,0);
        vector<int>arr2(128,0);
        for(int i=0;i<t.length();i++){
            arr1[t[i]]++;
        }

        int l=0;
        int r=0;
        for(r=0;r<s.length();r++){
            if(arr1[s[r]]>0){
                arr2[s[r]]++;
            }

            while(isValid(arr1,arr2)){
                if(r-l+1<minLen){
                    minLen=r-l+1;
                    startIndex=l;
                }
                if(arr2[s[l]]>0){
                    arr2[s[l]]--;
                }
                l++;
            }
        }
        if(startIndex==-1){
            return "";
        }
        return s.substr(startIndex,minLen);
    }
};
