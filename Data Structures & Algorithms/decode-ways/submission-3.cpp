class Solution {
public:
    void solve(int index, string& s, int& res){
        if(index>=s.length()){
            res++;
            return;
        }
        if(s[index] == '0'){
            return;
        }

        solve(index+1, s, res);

        if(index < s.length()-1){
            int num = (s[index] - '0')*10 + s[index+1] - '0';
            if(num > 26){
                return;
            }
            solve(index+2,s, res);
        }
        
    }
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }

        int res = 0;
        solve(0, s, res);
        return res;
    }
};
