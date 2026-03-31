// class Node{
//     public:
//     int val;
//     Node* next;

//     Node(int val){
//         this->val=val;
//         this->next=NULL;
//     }
// }
class Twitter {
public:
    // map: userID to arr (tweetID) pair<tweetID, posted>
    unordered_map<int,vector<pair<int,int>>> m1;

    // map: userID to linkedList(followers)
    unordered_map<int,unordered_set<int>> m2;
    
    int postOrder;


    Twitter() {
        postOrder=0;
    }
    
    void postTweet(int userId, int tweetId) {
        m1[userId].push_back({postOrder++,tweetId});
        return;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        int cnt = 0;
        int index = m1[userId].size()-1;
        while(cnt<=10 && index>=0){
            pq.push(m1[userId][index--]);
            cnt++;
        }
        // for(int i=0;i<m1[userId].size();i++){
        //     pq.push(m1[userId][i]);
        // }

        for(auto iter=m2[userId].begin();iter!=m2[userId].end();iter++){
            int user = *iter;
            cnt = 0;
            int index = m1[user].size()-1;
            while(cnt<=10 && index>=0){
                pq.push(m1[user][index--]);
                cnt++;
            }
            // for(int i=0;i<m1[user].size();i++){
            //     pq.push(m1[user][i]);
            // }
        }
        // cout<<pq.size()<<endl;
        vector<int>res;
        int count=10;
        while(count>0 && !pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            count--;
        }
        // cout<<res.size()<<endl;
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        m2[followerId].insert(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        m2[followerId].erase(followeeId);
        return;
    }
};
