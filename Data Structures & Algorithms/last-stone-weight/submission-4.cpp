class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size() > 1){
            int a = pq.top();pq.pop();
            int b = pq.top();pq.pop();
            if(abs(a-b) == 0){
                continue;
            }

            pq.push(abs(a-b));
        }
        if(pq.size() == 1){
            return pq.top();
        }
        return 0;
    }
};
