class Solution {
public:
    bool isEqual(vector<int>&arr1, vector<int>& arr2){
        for(int i=0;i<arr1.size();i++){
            if(arr1[i] < arr2[i]){
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        if(s.length() < t.length()){
            return "";
        }
        vector<int> arr1(128,0);
        vector<int> arr2(128,0);
        int start = 0;
        int len = INT_MAX;

        for(int i=0;i<t.length();i++){
            arr2[t[i] - 0]++;
        }

        int l=0;
        for(int r=0;r<s.length();r++){
            arr1[s[r] - 0]++;
            while(isEqual(arr1, arr2)){
                if(r-l+1 < len){
                    start = l;
                    len = r-l+1;
                } 
                arr1[s[l] - 0]--;
                l++;

            }
        }
        if(len == INT_MAX){
            return "";
        }
        return s.substr(start, len);
    }
};
