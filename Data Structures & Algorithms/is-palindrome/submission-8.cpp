class Solution {
public:
    bool isValid(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i] <= 'Z'){
                s[i] = s[i]+32;
            }
        }
        int i=0;
        int j=s.length()-1;

        while(i<j){
            while(!isValid(s[i]) && i<s.length()){
                i++;
            }
            while(!isValid(s[j]) && j>=0){
                j--;
            }

            if(i>j){
                break;
            }

            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
