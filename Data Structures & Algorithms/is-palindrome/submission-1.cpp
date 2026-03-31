class Solution {
public:
    bool isValid(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int i=0;
        int j=s.length()-1;

        for(int i=0;i<s.length();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i] = s[i] + 32;
            }
        }

        while(i<j){
            while(i<j && !isValid(s[i])){
                i++;
            }

            while(i<j && !isValid(s[j])){
                j--;
            }

            if(s[i++]!=s[j--]){
                return false;
            }
        }
        return true;
    }
};
