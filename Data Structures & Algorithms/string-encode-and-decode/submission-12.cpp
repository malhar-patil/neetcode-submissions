class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(int i=0;i<strs.size();i++){
            s.append("#!"); s.append(to_string(strs[i].size()));s.append("#");
            s.append(strs[i]);
        }
        return s;
    }

    vector<string> decode(string s) {
        if(s.length()==0){
            return {};
        }
        vector<string> res;
        for(int i=0;i<s.length()-1;i++){
            if(s[i]=='#' && s[i+1]=='!'){
                string len;
                int index = i+2;
                while(index<s.length() && s[index]!='#'){
                    len.push_back(s[index]);
                    index++;
                }
                int size = stoi(len);
                res.push_back(s.substr(index+1,size));
                i=index+size;
            }
        }
        return res;
    }
};
