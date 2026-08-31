class Solution {
public:

    string encode(vector<string>& strs) {
        string enc;
        for(int i=0;i<strs.size();i++){
            enc += '#';
            enc += to_string(strs[i].length());
            enc += '#';
            enc += strs[i];
        }

        return enc;
    }

    vector<string> decode(string s) {
        cout<<s<<endl;
        vector<string> res;
        int i=0;
        while(i<s.length()){
            int j = i+1;
            if(s[i] == '#'){
                while(s[j]!='#'){
                    j++;
                }
            }

            int num = stoi(s.substr(i+1, j-(i+1)+1));
            res.push_back(s.substr(j+1, num));
            i=j+1+num;

        }
        return res;
    }
};
