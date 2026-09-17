class Solution {
public:
    // bool isEqual(vector<int>&arr1, vector<int>& arr2){
    //     for(int i=0;i<arr1.size();i++){
    //         if(arr1[i] < arr2[i]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    string minWindow(string s, string t) {
        if(s.length() < t.length()){
            return "";
        }
        vector<int> arr1(128,0);
        vector<int> arr2(128,0);
        int start = 0;
        int len = INT_MAX;
        int cnt = 0;
        int cnt_t = 0;
        for(int i=0;i<t.length();i++){
            if(arr2[t[i] - 0] == 0){
                cnt_t++;
            }
            arr2[t[i] - 0]++;
        }
        cout<<cnt_t<<endl;

        int l=0;
        for(int r=0;r<s.length();r++){
            arr1[s[r] - 0]++;
            if(arr1[s[r] - 0] == arr2[s[r] - 0] && arr2[s[r] - 0] != 0){
                cnt++;
            }
            while(cnt == cnt_t){
                if(r-l+1 < len){
                    start = l;
                    len = r-l+1;
                }
                arr1[s[l] - 0]--;
                if(arr1[s[l] - 0] < arr2[s[l] - 0]){
                    cnt --;
                }
                l++;
            }
        }
        if(len == INT_MAX){
            return "";
        }
        return s.substr(start, len);
    }
};
