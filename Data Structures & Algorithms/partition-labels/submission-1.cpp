class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;

        for(int i=0;i<s.length();i++){
            m[s[i]] = i;
        }

        int size = 0;
        int e = 0;
        vector<int> ans;
        for(int i=0;i<s.length();i++){
            if(i > e){
                ans.push_back(size);
                size = 0;
            }
            e = max(e, m[s[i]]);
            size++;
        }
        ans.push_back(size);
        return ans;
    }
};
