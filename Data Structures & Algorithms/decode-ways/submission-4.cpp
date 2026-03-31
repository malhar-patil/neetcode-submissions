class Solution {
public:
    void solve(int index, string& s, int& res, unordered_map<int,int>& m){
        if(m.find(index) != m.end()){
            res+=m[index];
            return;
        }
        else if(index>=s.length()){
            res++;
            return;
        }
        else if(s[index] == '0'){
            return;
        }

        solve(index+1, s, res, m);

        if(index < s.length()-1){
            int num = (s[index] - '0')*10 + s[index+1] - '0';
            if(num > 26){
                return;
            }
            solve(index+2,s, res, m);
        }
        m[index] = res;
        
    }
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        int res = 0;
        unordered_map<int,int> m;
        solve(0, s, res, m);
        return res;
    }
};
