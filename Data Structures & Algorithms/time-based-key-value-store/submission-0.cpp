class TimeMap {
public:
    unordered_map<string, vector<pair<string,int>>> m;
    TimeMap() {
        string s = "test";
        pair<string,int> p = {"temp",0};
        vector<pair<string,int>> v;
        v.push_back(p);
        m[s] = v;
    }
    
    void set(string key, string value, int timestamp) {
        pair<string,int> p = {value,timestamp};
        if(m.find(key)==m.end()){
            vector<pair<string,int>> a;
            a.push_back(p);
            m[key] = a;
        }
        else{
            m[key].push_back(p);
        }
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> arr = m[key];
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;
        string ans = "";
        while(s<=e){
            if(arr[mid].second==timestamp){
                ans = arr[mid].first;
                break;
            }
            else if(arr[mid].second<timestamp){
                ans = arr[mid].first;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};
