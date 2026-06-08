class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int groups = hand.size()/groupSize;
        vector<pair<int,int>> arr (groups, {0,0});


        sort(hand.begin(), hand.end());

        // for(int i=0;i<hand.size();i++){
        //     cout<<hand[i]<<" ";
        // }cout<<endl;

        for(int i=0;i<hand.size();i++){
            // cout<<"-> "<<hand[i]<<endl;
            bool isPlaced = false;
            for(int j=0;j<arr.size();j++){\
                // cout<<"-> "<<arr[i].second<<" "<<arr[i].first<<endl;
                // cout<<"* "<<hand[i]<<endl;
                if(arr[j].second < groupSize && arr[j].first == hand[i] - 1){
                    arr[j] = {hand[i], arr[j].second + 1};
                    isPlaced = true;
                    break;
                }
                if(arr[j].first == 0 && arr[j].second == 0){
                    arr[j] = {hand[i], 1};
                    isPlaced = true;
                    break;
                }
            }

            // for(int i=0;i<arr.size();i++){
            //     cout<<arr[i].first<<" "<<arr[i].second<<", ";
            // }cout<<endl;

            if(isPlaced == false){
                return false;
            }

        }

        return true;
    }
};
