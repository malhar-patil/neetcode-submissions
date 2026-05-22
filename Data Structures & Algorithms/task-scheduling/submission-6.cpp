class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> heap;
        queue<pair<int,int>> q;
        vector<int> arr(26,0);

        for(int i=0;i<tasks.size();i++){
            arr[tasks[i]-'A']++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=0){
                heap.push(arr[i]);
            }
        }

        int time = 0;
        while(true){
            while(heap.empty() && (!q.empty() && q.front().second > time)){
                time++;
            }

            if(!q.empty() && q.front().second <= time){
                heap.push(q.front().first);
                q.pop();
            }

            int top = heap.top();
            heap.pop();
            top--;
            if(top > 0){
                q.push({top, time+n+1});
            }
            time++;
            if(heap.empty() && q.empty()){
                break;
            }
        }
        return time;
    }
};
