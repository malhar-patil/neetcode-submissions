class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string,int> newValue{value,timestamp};
        m[key].push_back(newValue);
    }
    
    string get(string key, int timestamp) {
        vector<pair<string,int>> arr = m[key];
        string ans;
        int s=0;
        int e=arr.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(arr[mid].second<=timestamp){
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
