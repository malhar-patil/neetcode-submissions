class Solution {
public:
    bool isEqual(vector<int>& arr1, vector<int>&arr2){
        for(int i=0;i<arr1.size();i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()){
            return false;
        }

        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        int len = s1.length();
        int l = 0;

        for(int i=0;i<s1.length();i++){
            arr1[s1[i] - 'a']++;
        }

        for(int i=0;i<s2.length();i++){
            if(i < len){
                arr2[s2[i] - 'a']++;
                continue;
            }

            if(isEqual(arr1, arr2)){
                return true;
            }
            arr2[s2[l] - 'a']--;
            l++;
            arr2[s2[i] - 'a']++;
        }
        if(isEqual(arr1, arr2)){
            return true;
        }
        return false;
    }
};
