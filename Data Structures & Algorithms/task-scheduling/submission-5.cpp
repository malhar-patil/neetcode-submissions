class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        queue<pair<int, int>> q;

        vector<int> arr(26, 0);
        for (int i = 0; i < tasks.size(); i++) {
            arr[tasks[i] - 'A']++;
        }
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                pq.push(arr[i]);
            }
        }
        int time = 0;
        while (true) {
            if (!q.empty() && q.front().second <= time) {
                pq.push(q.front().first);
                q.pop();
            }
            if (!pq.empty()) {
                int top = pq.top();
                pq.pop();
                top--;
                if (top > 0) {
                    q.push({top, time + n + 1});
                }
            }
            time++;
            if (pq.empty() && q.empty()) {
                break;
            }
        }
        return time;
    }
};