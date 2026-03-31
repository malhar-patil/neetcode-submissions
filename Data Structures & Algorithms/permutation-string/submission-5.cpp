class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        for(int i=0;i<s1.length();i++){
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        int l=0;
        for(int r=s1.length()-1;r<s2.length()-1;r++){
            if(arr1==arr2){
                return true;
            }
            arr2[s2[l++]-'a']--;
            arr2[s2[r+1]-'a']++;
        }
        if(arr1==arr2){
            return true;
        }
        return false;
    }
};
