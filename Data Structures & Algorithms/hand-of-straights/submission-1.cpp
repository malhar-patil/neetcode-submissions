class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }

        unordered_map<int,int> m;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0;i<hand.size();i++){
            m[hand[i]]++;
        }

        for(auto iter=m.begin();iter!=m.end();iter++){
            pq.push(iter->first);
        }
        
        while(!m.empty() && !pq.empty()){
            int num = pq.top();
            int iter = groupSize;

            while(iter>0){
                if(m.find(num) == m.end()){
                    return false;
                }

                m[num]--;
                if(m[num] == 0){
                    m.erase(num);
                    if(num != pq.top()){
                        return false;
                    }
                    else{
                        pq.pop();
                    }
                }
                num++;
                iter--;
            }
        }
        return true;
    }
};
