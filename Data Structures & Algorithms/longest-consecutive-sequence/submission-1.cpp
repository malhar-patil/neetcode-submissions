class Solution {
public:
    void printMap(unordered_map<int,bool>& m){
        for(auto iter = m.begin();iter!=m.end();iter++){
            cout<<iter->first<<" "<<iter->second<<endl;
        }
        cout<<"============"<<endl;
    }
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        unordered_map<int,bool> m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                continue;
            }
            else{
                m[nums[i]] = true;
            }
        }




        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i]-1)==m.end()){
                int temp=1;
                int num = nums[i];
                while(m.find(num+1)!=m.end()){
                    num++;
                    temp++;
                }
                ans=max(ans,temp);
            }

        }
        return ans;
    }
};
