class Solution {
public:
    void printArr(vector<int>arr){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v1(nums.size(),1);
        vector<int> v2(nums.size(),1);

        for(int i=1;i<nums.size();i++){
            v1[i] = v1[i-1] * nums[i-1];
        }

        for(int i=nums.size()-2;i>=0;i--){
            v2[i] = v2[i+1] * nums[i+1];
        }
        printArr(v1);
        printArr(v2);
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(v1[i] * v2[i]);
        }
        return ans;
    }
};


// newArr [1 1 2 8]
//newArr2 [1 6 24 48]