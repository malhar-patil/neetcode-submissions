class Solution {
public:
    vector<int> mergeArray(vector<int>& nums1, vector<int>& nums2){
        vector<int> ans;
        int i=0;
        int j=0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i++]);
            }
            else{
                ans.push_back(nums2[j++]);
            }
        }

        while(i<nums1.size()){
            ans.push_back(nums1[i++]);
        }

        while(j<nums2.size()){
            ans.push_back(nums2[j++]);
        }

        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>arr = mergeArray(nums1,nums2);
        if(arr.size()%2!=0){
            return (double)arr[arr.size()/2];
        }
        else{
            return (arr[arr.size()/2] + arr[arr.size()/2 - 1])/(double)2;
        }
    }
};
