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
        int start = 0;
        int len = 0;

        for(r=0;r<s.length();r++){
            arr2[s[r] - NULL]++;
            while(l<=r && isEqual(arr1, arr2)){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    start = l;
                    len = r-l+1;
                }

                arr2[s[l]-NULL]--;
                l++;
            }
        }
        return s.substr(start, len);
    }
};
