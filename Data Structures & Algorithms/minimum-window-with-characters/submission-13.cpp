class Solution {
public:

    bool isEqual(vector<int>&arr1, vector<int>&arr2){

        for(int i=0;i<arr2.size();i++){
            if(arr1[i] != 0 && arr1[i] > arr2[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.length() < t.length()){
            return "";
        }

        vector<int>arr1(128,0);
        vector<int>arr2(128,0);
        for(int i=0;i<t.length();i++){
            arr1[t[i] - NULL]++;
        }

        int l=0;
        int r=0;
        int minLen = INT_MAX;
        string ans;
        for(r=0;r<s.length();r++){
            arr2[s[r] - NULL]++;
            while(l<=r && isEqual(arr1, arr2)){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    ans=s.substr(l, r-l+1);
                }

                arr2[s[l]-NULL]--;
                l++;
            }
        }
        return ans;
    }
};
