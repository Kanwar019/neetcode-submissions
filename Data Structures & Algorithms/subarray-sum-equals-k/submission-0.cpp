class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        int cursum=0;
        unordered_map<int,int> prefixSums;
        prefixSums[0]=1;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            int diff= cursum-k;
            res+=prefixSums[diff];
            prefixSums[cursum]++;
            }
        return res;
    }
};