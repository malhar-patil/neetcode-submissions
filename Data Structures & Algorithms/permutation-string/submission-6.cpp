class Solution {
public:
    bool isSame(vector<int>& arr1, vector<int>&arr2){
        for(int i=0;i<arr1.size();i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length() >s2.length()){
            return false;
        }
        vector<int>arr1(26,0);
        for(int i=0;i<s1.length();i++){
            arr1[s1[i]-'a']++;
        }
        vector<int>arr2(26,0);
        int l=0;
        for(int r=0;r<s2.length();r++){
            arr2[s2[r]-'a']++;
            if(r-l+1 == s1.length()){
                if(isSame(arr1,arr2)){
                    return true;
                }
                else{
                    arr2[s2[l]-'a']--;
                    l++;
                }
            }
        }
        return false;
    }
};
