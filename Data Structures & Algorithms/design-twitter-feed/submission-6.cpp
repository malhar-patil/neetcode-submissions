class Twitter {
public:
    //map userid with tweet id
    unordered_map<int, vector<pair<int,int>>> m1;

    //map follower and followee
    unordered_map<int, list<int>> m2;

    int postCount;

    Twitter() {
        postCount = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        m1[userId].push_back({postCount, tweetId});
        postCount++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;

        for(auto it = m2[userId].begin(); it != m2[userId].end(); it++){
            for(int i=0;i<m1[*it].size();i++){
                pq.push(m1[*it][i]);
            }
        }

        for(int i=0;i<m1[userId].size();i++){
            pq.push(m1[userId][i]);
        }
        
        int top = 10;
        while(top>0 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            top--;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId){
            return;
        }
        auto it = find(m2[followerId].begin(), m2[followerId].end(), followeeId);
        if(it != m2[followerId].end()){
            return;
        }
        m2[followerId].push_back(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = find(m2[followerId].begin(), m2[followerId].end(), followeeId);

        if(it != m2[followerId].end()){
            m2[followerId].erase(it);
        }
    }
};
