class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=0;
        vector<int>arr(26,0);
        for(int i=0;i<tasks.size();i++){
            arr[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                pq.push(arr[i]);
            }
        }
        queue<pair<int,int>> q;
        while(true){
            if(!q.empty() && time==q.front().second){
                pq.push(q.front().first);
                q.pop();
            }
            
            if(!pq.empty()){
                int remaining = pq.top()-1;
                pq.pop();
                time++;
                if(remaining>0){
                    q.push({remaining,time+n});
                }
            }

            else{
                time++;
            }

            if(pq.empty() && q.empty()){
                break;
            }
        }
        return time;
    }
};
